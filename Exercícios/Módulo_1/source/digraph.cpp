#include "digraph.hpp"

using namespace sml;

/**!
 * Constructor default of the digraph class
 */
Digraph::Digraph(){/*EMPTY*/}

/**!
 * Constructor of the digraph class that initializes the
 * adjacency list and matrix basead on the value passed
 * in the parameter
 * @param numNodes The number of nodes on the digraph
 */
Digraph::Digraph(int numNodes){
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
void Digraph::printAdjList(){
    cout << endl;
    cout << "============================================" << endl;
    cout << "               ADJACENCY LIST               " << endl;
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
void Digraph::printAdjMatrix(){
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
void Digraph::printIncMatrix(){
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

int Digraph::getNumNodes(){
    return numNodes;
}

/**!
 *  This function returns the adjacency list.
 *
 *  @return The adjacency list.
*/
map<int,vector<int>> Digraph::getAdjList(){
    return adjList;
}

/**!
 *  This function returns the adjacency list.
 *
 *  @return The adjacency matrix.
*/
vector<vector<int>> Digraph::getAdjMatrix(){
    return adjMatrix;
}

/**!
 *  This function returns the incidence matrix.
 *
 *  @return The incidence matrix.
*/
vector<vector<int>> Digraph::getIncMatrix(){
    return incMatrix;
}

/**!
 * This function updates the adjacency list by replacing the 
 * actual one with the one passed as parameter.
 *
 *  @param adjList The new version of the adjacency list to be
 * updated
*/
void Digraph::updateAdjList(map<int, vector<int>> adjList){
    this->adjList = adjList;
}

/**!
 * This function updates the adjacency matrix by replacing the 
 * actual one with the one passed as parameter.
 *
 *  @param adjMatrix The new version of the adjacency matrix to be
 * updated
*/
void Digraph::updateAdjMatrix(vector<vector<int>> adjMatrix){
    this->adjMatrix = adjMatrix;
}

/**!
 * This function updates the incidence matrix by replacing the 
 * actual one with the one passed as parameter.
 *
 *  @param incMatrix The new version of the incidence matrix to be
 * updated
*/
void Digraph::updateIncMatrix(vector<vector<int>> incMatrix){
    this->incMatrix = incMatrix;
}

/**!
 * This function waits for any entry from the terminal to end.
 */
void Digraph::pause() {
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
int Digraph::manageVertex(){
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
pair<int,int> Digraph::manageEdge(){
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
void Digraph::runMenu() {
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
 * This function displays the digraph menu of the
 * simulation.
 */
void Digraph::displayMenu() {
  cout << "============================================" << endl;
  cout << "               DIGRAPH MENU                 " << endl;
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
 * This function adds a new vertex to the digraph along with its edges.
 * @param v The index of the vertex to be added
*/
void Digraph::addVertex(int v){
    /*TO-DO*/
}

/**!
 * This function adds a new edge to the digraph.
 * @param v A pair of integers representing the indexes
 * of the vertices to be connected
*/
void Digraph::addEdge(pair<int,int> v){
    /*TO-DO*/
}

/**!
 * This function removes a vertex to the digraph along with its edges
 * @param v The index of the vertex to be removed
*/
void Digraph::removeVertex(int v){
    /*TO-DO*/
}

/**!
 * This function removes an edge to the digraph.
 * @param v  A pair of integers representing the indexes
 * of the vertices to be disconnected
*/
void Digraph::removeEdge(pair<int,int> v){
    /*TO-DO*/
}