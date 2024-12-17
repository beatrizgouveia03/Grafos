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
  /// Enum para representar o resultado da simulação
  enum simulation_result_e
  {
    OK = 0,     //!< Todas as entradas estão como esperado.
    ERROR       //!< Alguma entrada está faltando ou possui erro.
  };

  /// Estrutura para armazenar o resultado da simulação
  struct SimulationResult
  {
    string msg;                 //!< Mensagem a ser exibida
    simulation_result_e type;   //!< Tipo de resultado da simulação

    SimulationResult(string msg, simulation_result_e state): msg(msg), type(state){};
  };

  /// Enum para representar o tipo de grafo
  enum graph_type_e
  {
    DIRECTED = 0,  //!< Grafo direcionado
    UNDIRECTED     //!< Grafo não direcionado
  };

  /// Estrutura para representar um grafo
  struct Graph
  {
    int n;                          //!< Número de vértices
    graph_type_e type;              //!< Tipo do grafo
    vector<vector<int>> adj;        //!< Matriz de adjacência
    map<int, string> dictionary;    //!< Lista que mantém o nome de cada vértice
  };

  class Simulation {
    //== Membros privados
    private:
      Graph graph;            //!< O grafo da simulação

    //=== Membros públicos
    public:
      Simulation(void);
      void run(void);
      SimulationResult initialize(int argc, char *argv[]);

    //=== Métodos auxiliares
    private:
      void pause(void);
      SimulationResult usage(string = "");
  };
} // namespace sml

#endif // SIMULATION_H
