#include "operations.hpp"

using namespace sml;

/**!
 * This function loops around the operations menu calling the
 * functions related to them, until the user chooses to return
 * to the main menu.
 */
void Operations::runMenu() {
  int opt = -1;
  string str;
  int nodeNum;

  while (opt != 0) {
    displayMenu();
    cout << "Enter your option: " << endl;
    getline(cin, str);
    opt = stoi(str);
    switch (opt) {
    case 1:
      adjListToAdjMatrix();
      break;
    case 2:
      adjMatrixToAdjList();
      break;
    case 3:
      calculateDegrees();
      break;
    case 4:
      adjacentsVertex();
      break;
    case 5:
      countVertices();
      break;
    case 6: 
      countEdges();
      break;
    case 7: 
      connected();
      break;
    case 8:
      bipartite();
      break;
    case 9:
      dfs();
      break;
    case 10:
      bfs();
      break;
    case 11:
      articulationsAndBlocks();
      break;
    case 12:
      subjacentGraph();
      break;
    case 13:
      incMatrixToDirectStar();
      break;
    case 14:
      directStarToIncMatrix();
      break;
    case 15:
      adjMatrixToIndirectStar();
      break;
    case 16:
      indirectStarToAdjMatrix();
      break;
    case 17:
      dfs();
      break;
    case 18:
      application();
      break;
    default:
      cout << "Select a valid option." << endl;
      break;
    }
  }  
}

/**!
 * This function waits for any entry from the terminal to end.
 */
void Operations::pause() {
  cout << "To return to the main menu, press Enter...";
  cin.get(); // Waits an entry
  cout << endl;
}

/**!
 * This function displays the digraph menu of the
 * simulation.
 */
void Digraph::displayMenu() {
  cout << "============================================" << endl;
  cout << "               OPERATIONS MENU              " << endl;
  cout << "============================================" << endl;
  cout << "1. Convert the graph from an adjacency list to an adjacency matrix" << endl;
  cout << "2. Convert the graph from an adjacency matrix to an adjacency list" << endl;
  cout << "3. Calculate the degrees of the vertex of the graph" << endl;
  cout << "4. Check if two vertices of the graph are adjacents" << endl;
  cout << "5. Count the vertices of the graph" << endl;
  cout << "6. Count the edges of the graph" << endl;
  cout << "7. Check if the graph is connected" << endl;
  cout << "8. Check if the graph is bipartite" << endl;
  cout << "9. Run a DFS on the graph" << endl;
  cout << "10. Run a BFS on the graph" << endl;
  cout << "11. Determinate the articulations and the block" << endl;
  cout << "12. Determinate the subjacent graph of the digraph" << endl;
  cout << "13. Convert the digraph from an incidence matrix to a direct star" << endl;
  cout << "14. Convert the digraph from a direct star to an incidence matrix" << endl;
  cout << "15. Convert the digraph from an adjacency matrix to an indirect star" << endl;
  cout << "16. Convert the digraph from an indirect star to an adjacency matrix" << endl;
  cout << "17. Run a DFS on the digraph" << endl;
  cout << "18. Show the application" << endl;  
  cout << "0. Exit to the main menu" << endl;
  cout << "============================================" << endl;
}

vector<vector<int>> Operations::adjListToAdjMatrix(map<int, vector<int>> adjList, int numNodes) {
  /*TO-DO*/
}

map<int, vector<int>> Operations::adjMatrixToAdjList(vector<vector<int>> adjMatrix, int numNodes) {
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
  if ((uAdj != adjList.end() && find(uAdj->second.begin(), uAdj->second.end(), v) != uAdj->second.end()) ||
      (vAdj != adjList.end() && find(vAdj->second.begin(), vAdj->second.end(), u) != vAdj->second.end())) {
    cout << v << " e " << u << " are adjacents." << endl;
  }
}

int Operations::countVertices(Graph g) { /*TO-DO*/ }

int Operations::countEdges(Graph g) { /*TO-DO*/ }

bool Operations::connected(Graph g) { /*TO-DO*/ }

bool Operations::bipartite(Graph g) { /*TO-DO*/ }

SearchResult Operations::dfs(Graph g, int v) {
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
  return SearchResult{.numNodes = numNodes,
                      .initialNode = v,
                      .predecessors = pred,
                      .visited = visited};
}

void Operations::bfs(Graph g, int v) { /*TO-DO*/ }

void Operations::articulationsAndBlocks(Graph g) { /*TO-DO*/ }

// THE MATH AND SEARCH OPERATIONS FROM DIGRAPHS
void Operations::subjacenteGraph(Digraph d) { /*TO-DO*/ }

void Operations::incMatrixToDirectStar(vector<vector<int>> incMatrix, int numNodes) {
  /*TO-DO*/
}

vector<vector<int>> Operations::directStarToIncMatrix(/*Dont know*/) {
  /*TO-DO*/
}

void Operations::adjMatrixToIndirectStar(vector<vector<int>> adjMatrix, int numNodes) {
  /*TO-DO*/
}

vector<vector<int>> Operations::indirectStarToAdjMatrix(/*Dont know*/) {
  /*TO-DO*/
}

void Operations::dfs(Digraph d) { /*TO-DO*/ }

void Operations::application() { /*TO-DO*/ }
