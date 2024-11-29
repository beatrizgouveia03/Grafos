#include "simulation.h"

using namespace sml;


/**!
 * Constructor default of the simulation class
 */
Simulation::Simulation(void) {
  // Initialize the simulation
  
}

/**!
 * This function waits for any entry from the terminal to end.
 */
void Simulation::pause(void){
  cout << "To return to the main menu, press Enter...";
  cin.get(); // Waits an entry
  cout << endl;
}


/**!
 * This function loops around the main menu calling the
 * functions related to them, until the user chooses to end the program.
 */
void Simulation::run(void) {
  int opt = -1;
  string str;

  cout << "Initializing simulation..." << endl;
}

/**!
 *  This function initializes the simulation by reading the input
 * file and creating representations of the graph as an adjancency
 *  list, as an adjacency matrix and as an incidence matrix.
 *
 * @param argc An integer indicating the amount of arguments passed on the
 * terminal
 * @param argv The list of the arguments passed on the terminal
 * @return  A struct indicating if was successful the initialization
 */
SimulationResult Simulation::initialize(int argc, char *argv[]) {
  // Initialize the simulation
  // Process command line arguments
  if (argc <= 1) {
    return usage("Error: Missing filename");
  } else {
    string filename = argv[1];
    ifstream file(filename);

    cout << "Initializing the simulation..." << endl;

    if (!file.is_open()) {
      return usage("Error: unable to open file");
    } else {

        /* TO - DO */

      // 1.Read the graph from the file
      
      // 2.Read the connections from the file
      
      // 3.Update the dictionary

      cout << "Sucessfully initialized" << endl;

      return SimulationResult("", simulation_result_e(0));
    }
  }
}

/**!
 *  This function shows in the terminal the usage options.
 *
 * @param message The usage error description message to be display 
 * @return  A struct indicating that the reading failed and the error message
 */
SimulationResult Simulation::usage(string message){
  if(message == "")
  {
    string usage = ">>> Usage: graph <input_entry_file>";

    return SimulationResult(usage, simulation_result_e(1));
  }

  return SimulationResult(">>> "+ message + "\n", simulation_result_e(1));
}
