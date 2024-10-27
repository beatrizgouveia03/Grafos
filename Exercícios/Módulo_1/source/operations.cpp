#include "operations.hpp"

using namespace sml;

vector<vector<int>>
Operations::adjListToAdjMatrix(map<int, vector<int>> adjList, int numNodes) {
  /*TO-DO*/
}

map<int, vector<int>>
Operations::adjMatrixToAdjList(vector<vector<int>> adjMatrix, int numNodes) {
  /*TO-DO*/
}

void Operations::calculateDegrees(Graph g) {
  // acessa a lista de adjacência que representa o grafo
  auto adjList = g.getAdjList();

  map<int, vector<int>>::iterator it;

  for (it = adjList.begin(); it != adjList.end(); ++it) {
    cout << "vertex " << it->first << " has ";

    int current_vertex_degree = 0;

    for (const int &edge : it->second) {
      current_vertex_degree++;
    }

    cout << current_vertex_degree << "degrees" << endl;
  }
}

void Operations::adjacentsVertex(Graph g, int u, int v) {
  // acessa a lista de adjacência que representa o grafo
  const auto &adjList = g.getAdjList();

  // localizando os vértices u e v dados na lista de adjacência
  auto uAdj = adjList.find(u);
  auto vAdj = adjList.find(v);

  // verificando se os vértices "u" e "v" existem na lista de adjacência e,
  // existindo, se possuem o outro no seu VETOR adjacentes
  if ((uAdj != adjList.end() && find(uAdj->second.begin(), uAdj->second.end(),
                                     v) != uAdj->second.end()) ||
      (vAdj != adjList.end() && find(vAdj->second.begin(), vAdj->second.end(),
                                     u) != vAdj->second.end())) {
    cout << v << " e " << u << " são adjacentes." << endl;
  }
}

int Operations::countVertices(Graph g) { /*TO-DO*/ }

int Operations::countEdges(Graph g) { /*TO-DO*/ }

bool Operations::connected(Graph g) { /*TO-DO*/ }

bool Operations::bipartite(Graph g) { /*TO-DO*/ }

sml::SearchResult Operations::dfs(Graph g, int v) {
  auto numNodes = g.getNumNodes();

  auto adjList = g.getAdjList();

  vector<bool> visited = vector(numNodes, false);
  vector<int> pred = vector(numNodes, -1);
  stack<int> s;

  visited[v] = true;
  s.push(v);

  while (!s.empty()) {
    int curr = s.top();
    s.pop();

    for (auto edge : adjList[v]) {
      if (!visited[edge]) {
        visited[edge] = true;
        pred[edge] = v;
        s.push(edge);
      }
    }
  }
  return sml::SearchResult{.numNodes = numNodes,
                           .initialNode = v,
                           .predecessors = pred,
                           .visited = visited};
}

void Operations::bfs(Graph g, int v) { /*TO-DO*/ }

void Operations::articulationsAndBlocks(Graph g) { /*TO-DO*/ }

// THE MATH AND SEARCH OPERATIONS FROM DIGRAPHS
void Operations::subjacenteGraph(Digraph d) { /*TO-DO*/ }

void Operations::incMatrixToDirectStar(vector<vector<int>> incMatrix,
                                       int numNodes) {
  /*TO-DO*/
}

vector<vector<int>> Operations::directStarToIncMatrix(/*Dont know*/) {
  /*TO-DO*/
}

void Operations::adjMatrixToIndirectStar(vector<vector<int>> adjMatrix,
                                         int numNodes) {
  /*TO-DO*/
}

vector<vector<int>> Operations::indirectStarToAdjMatrix(/*Dont know*/) {
  /*TO-DO*/
}

void Operations::dfs(Digraph d) { /*TO-DO*/ }

void Operations::application() { /*TO-DO*/ }
