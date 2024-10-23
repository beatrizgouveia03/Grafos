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
 *  This function printsthe adjacency list.
*/   
void Graph::printGraphAsAdjList(){
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
 *  This function printsthe adjacency matrix.
*/  
void Graph::printGraphAsAdjMatrix(){
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
void Graph::printGraphAsIncMatrix(){
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
 * This function adds a new vertex to the graph along with its edges.
*/
void Graph::addVertex(){
    /*TO-DO*/
}

/**!
 * This function adds a new edge to the graph.
 * @param u The first vertex of the edge
 *  @param v The second vertex of the edge
*/
void Graph::addEdge(int u, int v){
    /*TO-DO*/
}

/**!
 * This function removes a vertex to the graph along with its edges.
 *
 *  @param incMatrix The new version of the incidence matrix to be
 * updated
*/
void Graph::removeVertex(int vertex){
    /*TO-DO*/
}

/**!
 * This function removes an edge to the graph.
 * @param u The first vertex of the edge
 *  @param v The second vertex of the edge
*/
void Graph::removeEdge(int u, int v){
    /*TO-DO*/
}
