#ifndef SIMULATION_H
#define SIMULATION_H

/*!
 * @file simulation.hpp
 * @author Beatriz Gouveia
 * @date Oct 22nd, 2024
 */

#include "operations.hpp"
#include <string>
using std::stoi;
using std::string;

#include <fstream>
using std::ifstream;

#include <sstream>
using std::istringstream;

#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

#include <map>
using std::map;

#include <vector>
using std::vector;

#include "digraph.hpp"
#include "graph.hpp"

namespace sml {
class Simulation {
private:
  Graph graph;
  Digraph digraph;

  void pause();
  void manageGraph();
  void manageDigraph();

public:
  // Contructors and Destructors
  Simulation();
  Operations operations;

  void run();
  void displayMainMenu();
  void displayGraphMenu();
  void displayDigraphMenu();
  void initialize(int argc, char *argv[]);
};
} // namespace sml

#endif // SIMULATION_H
