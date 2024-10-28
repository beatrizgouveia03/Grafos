#include "operations.hpp"

using namespace sml;

/**!
 * Constructor default of the operations class
 */
Operations::Operations(){
  // Initialize the operations
  this->graph = Graph();
  this->digraph = Digraph();
}

/**!
 * Constructor of the operations class that initializes the
 * graph and the digraph basead on the values passed on the
 * parameters
 * @param g A copy of the graph to be initialized;
 * @param d A copy of the digraph to be initialized;
 */
Operations::Operations(Graph g, Digraph d){
  this->graph = g;
  this->digraph = d;
}

int Operations::handleSearch(int v){
  int x;

  cout << "Insert the index of the vertex to start the search: " << endl;
  cin >> x;

  if( x<=0 ) {
        cout << "Insert a valid index." << endl;
        return handleSearch(int());
    }
    else {
        return x;
    }

  return x;

}

pair<int,int> Operations::handleSearch(pair<int,int> v){
  int x, y;

    cout << "Insert the index of the first vertex: " << endl;
    cin >> x;
    cout << "Insert the index of the second vertex: " << endl;
    cin >> y;

    if( x<=0 || y<=0 ) {
        cout << "Insert a valid index." << endl;
        return handleSearch(pair<int,int>());
    }
    else {
        return make_pair(x, y);
    }
}

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
      dfs(graph, handleSearch(int()));
      pause();
      break;
    case 2:
      bfs(graph, handleSearch(int()));
      pause();
      break;
    case 3:
      countEdges(graph);
      break;
    case 4:
      countVertices(graph);
      break;
    case 5:
      connected(graph);
      break;
    case 6: 
      bipartite(graph);
      break;
    case 7: 
      calculateDegrees(graph);
      break;
    case 8:
      adjacentsVertex(graph, handleSearch(pair<int,int>()));
      break;
    case 9:
      articulationsAndBlocks(graph);
      break;
    case 10:
      adjListToAdjMatrix(graph.getAdjList());
      break;
    case 11:
      adjMatrixToAdjList(graph.getAdjMatrix());
      break;
    case 12:
      dfs(digraph, handleSearch(int()));
      break;
    case 13:
      application();
      break;
    case 14:
      subjacentGraph(digraph);
      break;
    case 15:
      incMatrixToDirectStar(digraph.getIncMatrix());
      break;
    case 16:
      directStarToIncMatrix();
      break;
    case 17:
      adjMatrixToIndirectStar(digraph.getAdjMatrix());
      break;
    case 18:
      indirectStarToAdjMatrix();
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
void Operations::displayMenu() {
  cout << "============================================" << endl;
  cout << "               OPERATIONS MENU              " << endl;
  cout << "============================================" << endl;
  cout << "---------------Graph Operations-------------" << endl;
  cout << "1. Run a DFS" << endl;
  cout << "2. Run a BFS" << endl;
  cout << "3. Count the edges" << endl;
  cout << "4. Count the vertices" << endl;
  cout << "5. Check if is connected" << endl;
  cout << "6. Check if is bipartite" << endl;
  cout << "7. Calculate the degrees of the vertex" << endl;
  cout << "8. Check if two vertices are adjacents" << endl;
  cout << "9. Determinate the articulations and the block" << endl;
  cout << "10. Convert adjacency matrix to an adjacency list" << endl;
  cout << "11. Convert adjacency list to an adjacency matrix" << endl;
  cout << "--------------Digraph Operations------------" << endl;
  cout << "12. Run a DFS" << endl;
  cout << "13. Show the application" << endl;  
  cout << "14. Determinate the subjacent graph" << endl;
  cout << "15. Convert incidence matrix to a direct star" << endl;
  cout << "16. Convert direct star to an incidence matrix" << endl;
  cout << "17. Convert adjacency matrix to an indirect star" << endl;
  cout << "18. Convert indirect star to an adjacency matrix" << endl;
  cout << "0. Exit to the main menu" << endl;
  cout << "============================================" << endl;
}


/**!
 * This function converts the adjacency list of the graph to an 
 * adjacency matrix and displays the matrix resultant in the terminal
 * @param adjList The adjacency list to be converted
 */
void Operations::adjListToAdjMatrix(map<int, vector<int>> adjList) {
  /*TO-DO*/
}


/**!
 * This function converts the adjacency matrix of the graph to an 
 * adjacency list and displays the list resultant in the terminal
 * @param adjMatrix The adjacency matrix to be converted
 */
void Operations::adjMatrixToAdjList(vector<vector<int>> adjMatrix) {
  /*TO-DO*/
}

/**!
 * This function calculates the degree of each vertex and displays
 * on the terminal
 * @param g The graph to be calculated
 */
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

/**!
 * This function checks if two vertices of the graph are adjacents
 * @param g The graph to be checked
 * @param vs A pair of integers indicating the indexes of the vertices
 */
void Operations::adjacentsVertex(Graph g, pair<int,int> vs) {
  int u = vs.first, v = vs.second;

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

/**!
 * This function counts the amount of the vertices of the graph and displays
 * on the terminal
 * @param g The graph to be calculated
 * @returns The amount of vertices of the graph
 */
void Operations::countVertices(Graph g) { 
  /*TO-DO*/
}

/**!
 * This function counts the amount of the vertices of the graph and displays
 * on the terminal
 * @param g The graph to be calculated
 * @returns The amount of vertices of the graph
 */
void Operations::countEdges(Graph g) { 
  /*TO-DO*/
}

/**!
 * This function checks if the graph is connected and displays the result 
 * in the terminal
 * @param g The graph to be checked
 */
void Operations::connected(Graph g) { 
  /*TO-DO*/
}

/**!
 * This function checks if the graph is bipartite and displays the result 
 * in the terminal
 * @param g The graph to be checked
 */
void Operations::bipartite(Graph g) {
  /*TO-DO*/
}

/**!
 * This function does a Depth-First Search(DFS) in the graph beggining 
 *  in the vertex "v" and displays the result in the terminal
 * @param g The graph to be checked
 * @param v The index of the initial search vertex
 * @return The search result to be displayed
 */
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

/**!
 * This function does a Breadth-First Search(BFS) in the graph beggining 
 *  in the vertex "v" and displays the result in the terminal
 * @param g The graph to be checked
 * @param v The index of the initial search vertex
 * @return The search result to be displayed
 */
SearchResult Operations::bfs(Graph g, int v) { /*TO-DO*/ }

/**!
 * This function determinates the articulations and the blocks of the graph
 * and displays in the terminal
 * @param g The graph to be checked
 */
void Operations::articulationsAndBlocks(Graph g) { /*TO-DO*/ }

// THE MATH AND SEARCH OPERATIONS FROM DIGRAPHS

/**!
 * This function determinates the subjacent graph of the digraph
 * @param d The digraph to be used
 */
void Operations::subjacentGraph(Digraph d) { /*TO-DO*/ }

/**!
 * This function converts the incidence matrix of the digraph to an 
 * direct star and displays the list resultant in the terminal
 * @param adjMatrix The incidence matrix to be converted
 */
void Operations::incMatrixToDirectStar(vector<vector<int>> incMatrix) {
  /*TO-DO*/
}


/**!
 * This function converts the direct star of the digraph to an 
 * incidence matrix and displays the list resultant in the terminal
 * @param dirStar The direct star to be converted
 */
void Operations::directStarToIncMatrix(/*Dont know*/) {
  /*TO-DO*/
}

/**!
 * This function converts the adjacency matrix of the digraph to an 
 * indirect star and displays the list resultant in the terminal
 * @param adjMatrix The adjacency matrix to be converted
 */
void Operations::adjMatrixToIndirectStar(vector<vector<int>> adjMatrix) {
  /*TO-DO*/
}

/**!
 * This function converts the indirect star of the digraph to an 
 * adjacency matrix and displays the list resultant in the terminal
 * @param dirStar The indirect star to be converted
 */
void Operations::indirectStarToAdjMatrix(/*Dont know*/) {
  /*TO-DO*/
}

/**!
 * This function does a Depth-First Search(DFS) in the digraph beggining 
 *  in the vertex "v" and displays the result in the terminal
 * @param d The digraph to be checked
 * @param v The index of the initial search vertex
 * @return The search result to be displayed
 */
SearchResult Operations::dfs(Digraph d, int v) { /*TO-DO*/ }

void Operations::application() { /*TO-DO*/ }
