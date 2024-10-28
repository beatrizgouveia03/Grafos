#include "graph.hpp"

using namespace sml;


/**!
 * Constructor default of the graph class
 */
Graph::Graph(){/*EMPTY*/}

/**!
 * Constructor of the graph class that initializes the
 * adjacency list and matrix basead on the value passed
 * in the parameter
 * @param numNodes The number of nodes on the graph
 */
Graph::Graph(int numNodes){
    this->numNodes = numNodes;

   // Inicialize the adjancency list
    cout << "Initializing the adjacency list..." << endl;

    for(size_t i{1}; i <= numNodes; ++i){
        adjList[i];
    }
    cout << "Adjacency list initialized succefully" << endl;
    
    //Inicialize the adjacency matrix
    cout << "Initializing the adjacency matrix..." << endl;

    adjMatrix = vector<vector<int>> (numNodes, vector<int>(numNodes, 0));


    cout << "Adjacency matrix initialized succefully" << endl;

}

/**!
 *  This function prints the adjacency list.
*/   
void Graph::printAdjList(){
    cout << endl;
    cout << "============================================" << endl;
    cout << "               ADJACENCY LIST                " << endl;
    cout << "============================================" << endl;
    for(int i = 1; i <= numNodes; i++){
        
        cout << "Adjacency list of node " << i << " : ";
        for(int j = 0; j < adjList[i].size(); j++){
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "============================================" << endl;
}

/**!
 *  This function prints the adjacency matrix.
*/  
void Graph::printAdjMatrix(){
    cout << endl;
    cout << "============================================" << endl;
    cout << "              ADJACENCY MATRIX              " << endl;
    cout << "============================================" << endl;
    cout << "\\ ";
    for(int j = 0; j < numNodes; j++){
        cout << " " << j+1;
    }
    cout << endl;

    cout << "  ";
    for(int j = 0; j < numNodes; j++){
        cout << "--";
    }
    cout << endl;

    for(int i = 0; i < numNodes; i++){
        cout << i+1 << "| ";
        for(int j = 0; j < numNodes; j++){
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "============================================" << endl;
}

/**!
 *  This function prints the incidence matrix.
*/        
void Graph::printIncMatrix(){
    cout << endl;
    cout << "============================================" << endl;
    cout << "              INCIDENCE MATRIX              " << endl;
    cout << "============================================" << endl;
    cout << "\\ ";
    for(int j = 0; j < numNodes; j++){
        cout << " " << j+1;
    }
    cout << endl;

    cout << "  ";
    for(int j = 0; j < numNodes; j++){
        cout << "--";
    }
    cout << endl;

    for(int i = 0; i < incMatrix.size(); i++){
        cout << i+1 << "| ";
        for(int j = 0; j < numNodes; j++){
            cout << incMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "============================================" << endl;
}

/**!
    This function returns the numbers of node.
  *
  *
  * @return Number of nodes
 */

int Graph::getNumNodes(){
    return numNodes;
}

/**!
 *  This function returns the adjacency list.
 *
 *  @return The adjacency list.
*/
map<int,vector<int>> Graph::getAdjList(){
    return adjList;
}

/**!
 *  This function returns the adjacency list.
 *
 *  @return The adjacency matrix.
*/
vector<vector<int>> Graph::getAdjMatrix(){
    return adjMatrix;
}

/**!
 *  This function returns the incidence matrix.
 *
 *  @return The incidence matrix.
*/
vector<vector<int>> Graph::getIncMatrix(){
    return incMatrix;
}

/**!
 * This function updates the adjacency list by replacing the 
 * actual one with the one passed as parameter.
 *
 *  @param adjList The new version of the adjacency list to be
 * updated
*/
void Graph::updateAdjList(map<int, vector<int>> adjList){
    this->adjList = adjList;
}

/**!
 * This function updates the adjacency matrix by replacing the 
 * actual one with the one passed as parameter.
 *
 *  @param adjMatrix The new version of the adjacency matrix to be
 * updated
*/
void Graph::updateAdjMatrix(vector<vector<int>> adjMatrix){
    this->adjMatrix = adjMatrix;
}

/**!
 * This function updates the incidence matrix by replacing the 
 * actual one with the one passed as parameter.
 *
 *  @param incMatrix The new version of the incidence matrix to be
 * updated
*/
void Graph::updateIncMatrix(vector<vector<int>> incMatrix){
    this->incMatrix = incMatrix;
}

/**!
 * This function waits for any entry from the terminal to end.
 */
void Graph::pause() {
  cout << "To return to the main menu, press Enter...";
  cin.get(); // Waits an entry
  cout << endl;
}

/**!
 * This function collects the index of the vertex that is 
 * wanted to be removed/inserted and returns it to the
 * caller.
 * @return An integer indication the index of the vertex
 */
int Graph::manageVertex(){
    int x;
    string str;

    cout << "Insert the index of the vertex: " << endl;
    getline(cin, str);
    x = stoi(str);

    if( x<=0 ) {
        cout << "Insert a valid index." << endl;
        return manageVertex();
    }
    else {
        return x;
    }
}

/**!
 * This function collects the index of the vertices of the edge
 * that is wanted to be removed/inserted and returns it to the
 * caller.
 * @return A pair of integers indication the indexes of the edge
 */
pair<int,int> Graph::manageEdge(){
    int x, y;
    string str;

    cout << "Insert the index of the first vertex: " << endl;
    getline(cin, str);
    x = stoi(str);
    cout << "Insert the index of the second vertex: " << endl;
    getline(cin, str);
    y = stoi(str);

    if( x<=0 || y<=0 ) {
        cout << "Insert a valid index." << endl;
        return manageEdge();
    }
    else {
        return make_pair(x, y);
    }
}


/**!
 * This function loops around the graph menu calling the
 * functions related to them, until the user chooses to return
 * to the main menu.
 */
void Graph::runMenu() {
  int opt = -1;
  string str;

  while (opt != 0) {
    displayMenu();
    cout << "Enter your option: " << endl;
    getline(cin, str);
    opt = stoi(str);
    switch (opt) {
    case 1:
        addEdge(manageEdge());
        pause();
        break;
    case 2:
        addVertex(manageVertex());
        pause();
        break;
    case 3:
        removeEdge(manageEdge());
        pause();
        break;
    case 4:
        removeVertex(manageVertex());
        pause();
        break;
    case 5:
        printAdjList();
        pause();
        break;
    case 6:
        printAdjMatrix();
        pause();
        break;
    case 7:
        printIncMatrix();
        pause();
        break;
    default:
      cout << "Select a valid option." << endl;
      break;
    }
  }  
}

/**!
 * This function displays the graph menu of the
 * simulation.
 */
void Graph::displayMenu() {
  cout << "============================================" << endl;
  cout << "               GRAPH MENU                 " << endl;
  cout << "============================================" << endl;
  cout << "1. Add edge." << endl;
  cout << "2. Add vertex" << endl;
  cout << "3. Remove edge." << endl;
  cout << "4. Remove vertex." << endl;
  cout << "5. Display as adjacency list" << endl;
  cout << "6. Display as adjacency matrix" << endl;
  cout << "7. Display as incidence matrix" << endl;
  cout << "0. Exit to the main menu" << endl;
  cout << "============================================" << endl;
}

/**!
 * This function adds a new vertex to the graph along with its edges.
 * @param v The index of the vertex to be added
*/
void Graph::addVertex(int v){
    /*TO-DO*/
}


/**!
 * This function adds a new edge to the graph.
 * @param v A pair of integers representing the indexes
 * of the vertices to be connected
*/
void Graph::addEdge(pair<int,int> v){
    /*TO-DO*/
}

/**!
 * This function removes a vertex to the graph along with its edges
 * @param v The index of the vertex to be removed
*/
void Graph::removeVertex(int v){
    /*TO-DO*/
}

/**!
 * This function removes an edge to the graph.
 * @param v  A pair of integers representing the indexes
 * of the vertices to be disconnected
*/
void Graph::removeEdge(pair<int,int> v){
    /*TO-DO*/
}
