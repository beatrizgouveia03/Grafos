#include "simulation.hpp"

using namespace sml;


void Simulation::pause() {
    cout << "Para retornar ao menu, pressione Enter...";
    cin.get();  // Espera o Enter
    cout << endl;
}

/**!
 * Constructor default of the simulation class
 */
Simulation::Simulation(){
    // Initialize the simulation
    this->graph = Graph();
    this->digraph = Digraph();
}

/**!
 * This function loops around the graph menu calling the 
 * functions related to them, until the user chooses to return
 * to the main menu. 
*/
void Simulation::manageGraph(){
    int opt = 0;
    string str;

    while(opt != 4){
        displayGraphMenu();
        cout << "Enter your option: " << endl;
        getline(cin, str);
        opt = stoi(str);
        switch(opt){
            case 1: graph.printGraphAsAdjList(); 
                pause();              
                break;
            case 2: graph.printGraphAsAdjMatrix();
                pause();
                break;  
            case 3: graph.printGraphAsIncMatrix();
                pause();
                break;
            default: cout << "Selecione uma opção válida" << endl; 
                break;
        }
    }
}

/**!
 * This function loops around the digraph menu calling the 
 * functions related to them, until the user chooses to return
 * to the main menu. 
*/
void Simulation::manageDigraph(){
    int opt = 0;
    string str;

    while(opt != 4){
        displayDigraphMenu();

        cout << "Enter your option: " << endl;
        getline(cin, str);
        opt = stoi(str);

        switch(opt){
            case 1: digraph.printDigraphAsAdjList();
                pause();
                break;
            case 2: digraph.printDigraphAsAdjMatrix();
                pause();
                break;  
            case 3: digraph.printDigraphAsIncMatrix();
                pause();
                break;
            default: cout << "Selecione uma opção válida" << endl; 
                break;
        }
    }
}

/**!
 * This function displays the main menu of the 
 * simulation.
*/
void Simulation::displayMainMenu(){
    cout << "============================================" << endl;
    cout << "                MAIN MENU                   " << endl;
    cout << "============================================" << endl;
    cout << "1. Graph options" << endl;
    cout << "2. Digraph options" << endl;
    cout << "3. Exit" << endl;
    cout << "============================================" << endl;
}

/**!
 * This function displays the graph menu of the
 * simulation. 
*/ 
void Simulation::displayGraphMenu(){
    cout << "============================================" << endl;
    cout << "               GRAPH MENU                 " << endl;
    cout << "============================================" << endl;
    cout << "1. Display as adjacency list" << endl;
    cout << "2. Display as adjacency matrix" << endl;
    cout << "3. Display as incidence matrix" << endl;
    cout << "4. Exit to the main menu" << endl;
    cout << "============================================" << endl;
}

/**!
 * This function displays the digraph menu of the
 * simulation.
*/ 
void Simulation::displayDigraphMenu(){
    cout << "============================================" << endl;
    cout << "               DIGRAPH MENU                 " << endl;
    cout << "============================================" << endl;
    cout << "1. Display as adjacency list" << endl;
    cout << "2. Display as adjacency matrix" << endl;
    cout << "3. Display as incidence matrix" << endl;
    cout << "4. Exit to the main menu" << endl;
    cout << "============================================" << endl;
}

/**!
 * This function loops around the main menu calling the 
 * functions related to them, until the user chooses to end the program. 
*/ 
void Simulation::run(){
    int opt = 0;
    string str;

    while(opt != 3){
        displayMainMenu();
        
        cout << "Enter your option: " << endl;
        getline(cin, str);
        opt = stoi(str);

        switch(opt){
            case 1: manageGraph();
                    break;
            case 2: manageDigraph();
                    break;
            default:break;
        }
    }
}

/**!
 *  This function initializes the simulation by reading the input 
 * file and creating representations of the graph as an adjancency
 *  list, as an adjacency matrix and as an incidence matrix.
 * 
 * @param argc An integer indicating the amount of arguments passed on the terminal
 * @param argv The list of the arguments passed on the terminal
*/   
void Simulation::initialize(int argc, char *argv[]){
    // Initialize the simulation
    // Process command line arguments
    if(argc <= 1){
        cerr << "Error: Missing filename" << endl;
        return;
    }
    else{
        string filename = argv[1];
        ifstream file(filename);
        
        cout << "Initializing the simulation..." << endl;

        if(!file.is_open()){
            cerr << "Error: unable to open file " << filename << endl;
            return;
        }
        else{

            // Read the graph from the file
            int x, y;
            int numNodes, numConnection = 0;

            string line;
            char trash;

            cout << "Reading number of nodes..." << endl;
            
            file >> numNodes;

            cout << "Numbers of nodes read: " << numNodes << endl;

            this->graph = Graph(numNodes);
            this->digraph = Digraph(numNodes);

            map<int, vector<int>> adjList = graph.getAdjList();
            vector<vector<int>> adjMatrix = graph.getAdjMatrix();
            vector<vector<int>> incMatrix = graph.getIncMatrix();

            //Read the connections from the file
            while(getline(file, line)){
                if(line == string()) continue;

                istringstream ss(line);
                ss >> x >> trash >> y;

                cout << "Reading connection " << x << " " << y << endl;

                if(x <= 0 | x > numNodes | y <= 0 | y > numNodes){
                    cerr << "Error: Node out-of-index" << endl;
                    return;
                }

                //Update the adjacency list
                adjList[x].push_back(y);
                adjList[y].push_back(x);

                cout << "Sucessfully addded connection in the adjacency list" << endl;

                //Update the adjancency matrix
                adjMatrix[x-1][y-1] = 1;
                adjMatrix[y-1][x-1] = 1;

                cout << "Sucessfully addded connection in the adjacency matrix" << endl;

                //Update the incidence matrix
                incMatrix.push_back(vector<int>(numNodes, 0));        

                incMatrix[numConnection][x-1] = 1;
                incMatrix[numConnection][y-1] = 1;

                cout << "Sucessfully addded connection in the incidence matrix" << endl;

                numConnection++;
            }
            cout << "Sucessfully read all connections from the file" << endl << endl;

            graph.updateAdjList(adjList);
            graph.updateAdjMatrix(adjMatrix);
            graph.updateIncMatrix(incMatrix);

            cout << "Sucessfully updated all the graph" << endl;
        }

    }
}

