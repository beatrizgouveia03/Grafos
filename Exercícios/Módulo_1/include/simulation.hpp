#ifndef SIMULATION_H
#define SIMULATION_H

/*!
 * @file simulation.hpp
 * @author Beatriz Gouveia
 * @date Oct 22nd, 2024
 */


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

#include "graph.hpp"
#include "digraph.hpp"
#include "operations.hpp"

namespace sml {
class Simulation {
private:
  Graph graph;
  Digraph digraph;
  Operations operations;

  void pause();
  void displayMainMenu();
  void readGraph(int x);
  

public:
  // Contructors and Destructors
  Simulation();

  void run();
  void initialize(int argc, char *argv[]);
};
} // namespace sml

#endif // SIMULATION_H
