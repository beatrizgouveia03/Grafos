#ifndef SIMULATION_H
#define SIMULATION_H

/*!
 * @file simulation.h
 * @author Beatriz Gouveia
 * @date Nov 29nd, 2024
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


namespace sml {
  /// Simulation Result Machine
  enum simulation_result_e
  {
    OK = 0,     //!< All the entries are as expect.
    ERROR       //!< Some entry is missing something.
  };

  /// Simulation Machine
  struct SimulationResult
  {
    string msg;                 //!< The message to be printed
    simulation_result_e type;   //!< The simulation result

    SimulationResult(string msg, simulation_result_e state): msg(msg), type(state){};
  };

  ///Graph Type Machine
  enum graph_type_e
  {
    DIRECTED = 0,  //!< Directed graph
    UNDIRECTED  //!< Undirected graph
  };

  /// Graph Struct Machine
  struct Graph
  {
    int n;                          //!< Number of vertices
    graph_type_e type;              //!< Type of the graph
    vector<vector<int> > adj;       //!< Adjacency matrix
    map<int, string> dictionary;    //!< The list that keeps the name of each vertex;
  };

  class Simulation {
    //== Private Members
    private:
      Graph graph;            //!< The graph of the simulation

    //=== Public Members
    public:
      Simulation(void);
      void run(void);
      SimulationResult initialize(int argc, char *argv[]);

    //=== Aux methods
    private:
      void pause(void);
      SimulationResult usage(string = "");
  };
} // namespace sml

#endif // SIMULATION_H
