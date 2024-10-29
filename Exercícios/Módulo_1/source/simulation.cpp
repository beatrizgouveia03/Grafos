#include "simulation.hpp"

using namespace sml;


/**!
 * Constructor default of the simulation class
 */
Simulation::Simulation() {
  // Initialize the simulation
  this->graph = Graph();
  this->digraph = Digraph();
  this->operations = Operations();
}

/**!
 * This function displays the main menu of the
 * simulation.
 */
void Simulation::displayMainMenu() {
  cout << "============================================" << endl;
  cout << "                MAIN MENU                   " << endl;
  cout << "============================================" << endl;
  cout << "1. Graph options" << endl;
  cout << "2. Digraph options" << endl;
  cout << "3. Operations options" << endl;
  cout << "0. Exit the simulation" << endl;
  cout << "============================================" << endl;
}


/**!
 * This function loops around the main menu calling the
 * functions related to them, until the user chooses to end the program.
 */
void Simulation::run() {
  int opt = -1;
  string str;

  while (opt != 0) {
    displayMainMenu();

    cout << "Enter your option: " << endl;
    getline(cin, str);
    opt = stoi(str);

    switch (opt) {
      case 0:
        break;
      case 1:
        graph.runMenu();
        break;
      case 2:
        digraph.runMenu();
        break;
      case 3:
        operations.runMenu();
        break;
      default:
        break;
      }
  }
}

/**!
 *  This function initializes the simulation by reading the input
 * file and creating representations of the graph as an adjancency
 *  list, as an adjacency matrix and as an incidence matrix.
 *
 * @param argc An integer indicating the amount of arguments passed on the
 * terminal
 * @param argv The list of the arguments passed on the terminal
 */
void Simulation::initialize(int argc, char *argv[]) {
  // Initialize the simulation
  // Process command line arguments
  if (argc <= 1) {
    cerr << "Error: Missing filename" << endl;
    return;
  } else {
    string filename = argv[1];
    ifstream file(filename);

    cout << "Initializing the simulation..." << endl;

    if (!file.is_open()) {
      cerr << "Error: unable to open file " << filename << endl;
      return;
    } else {

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

      // Read the connections from the file
      while (getline(file, line)) {
        if (line == string())
          continue;

        istringstream ss(line);
        ss >> x >> trash >> y;

        cout << "Reading connection " << x << " " << y << endl;

        if (x <= 0 | x > numNodes | y <= 0 | y > numNodes) {
          cerr << "Error: Node out-of-index" << endl;
          return;
        }

        // Update the adjacency list
        adjList[x].push_back(y);
        adjList[y].push_back(x);

        cout << "Sucessfully addded connection in the adjacency list" << endl;

        // Update the adjancency matrix
        adjMatrix[x - 1][y - 1] = 1;
        adjMatrix[y - 1][x - 1] = 1;

        cout << "Sucessfully addded connection in the adjacency matrix" << endl;

        // Update the incidence matrix
        incMatrix.push_back(vector<int>(numNodes, 0));

        incMatrix[numConnection][x - 1] = 1;
        incMatrix[numConnection][y - 1] = 1;

        cout << "Sucessfully addded connection in the incidence matrix" << endl;

        numConnection++;
      }
      cout << "Sucessfully read all connections from the file" << endl << endl;

      graph.updateAdjList(adjList);
      graph.updateAdjMatrix(adjMatrix);
      graph.updateIncMatrix(incMatrix);

      operations = Operations(graph, digraph);

      cout << "Sucessfully updated all the graph" << endl;
    }
  }
}
