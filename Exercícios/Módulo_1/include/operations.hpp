#ifndef OPERATIONS_H
#define OPERATIONS_H

/*!
 * @file operations.hpp
 * @author Beatriz Gouveia
 * @date Oct 22nd, 2024
 */

#include <algorithm>
#include <iomanip>

#include <map>
using std::map;

#include <vector>
using std::vector;

#include <stack>
using std::stack;

#include <iostream>
using std::cin;
using std::cout;
using std::left;
using std::endl;
using std::setw;
using std::setfill;
using std::ostream;
using std::istringstream;

#include "graph.hpp"
#include "digraph.hpp"

namespace sml {
  struct SearchResult {
    int numNodes;
    int initialNode;
    vector<int> predecessors;
    vector<bool> visited;

    friend ostream &operator<<(ostream &os, const SearchResult &result) {
      os << left; // Align to the left

      // Print header
      os << setw(15) << "Node" << setw(15) << "Visited" << setw(15)
        << "Predecessor" << '\n';

      // Print separator
      os << setfill('-') << setw(45) << "" << setfill(' ') << '\n';

      // Print each node's information
      for (int i = 1; i <= result.numNodes; ++i) {
        os << setw(15) << i                      // Node number
          << setw(15) << result.visited[i]      // Visited status
          << setw(15) << result.predecessors[i] // Predecessor
          << '\n';
      }

      return os;
    }
  };

class Operations {
  //== Private Members
  private:
    Graph graph;
    Digraph digraph;

  //== Public Members
  public:
    //Constructors
    Operations();
    Operations(Graph g, Digraph d);


    //Menu
    void runMenu();

    //Update(set) methods
    void updateGraph();
    void updateDigraph();
  
  //== Aux Members
  private:
    void pause();
    void displayMenu();
    string handleSearch(string v);
    pair<string,string> handleSearch(pair<string,string> v);

  // THE MATH AND SEARCH OPERATIONS FROM GRAPHS
    void adjListToAdjMatrix(map<int, vector<int>> adjLists);
    void adjMatrixToAdjList(vector<vector<int>> adjMatrix);
    void calculateDegrees(Graph g);
    void adjacentsVertex(Graph g, pair<string,string> vs);
    void countVertices(Graph g);
    void countEdges(Graph g);
    void connected(Graph g);
    void bipartite(Graph g);
    void dfs(Graph g, string v);
    void bfs(Graph g, string v);
    void articulationsAndBlocks(Graph g);

    // THE MATH AND SEARCH OPERATIONS FROM DIGRAPHS
    void subjacentGraph(Digraph d);
    void incMatrixToDirectStar(vector<vector<int>> incMatrix);
    void directStarToIncMatrix(/*Dont know*/);
    void adjMatrixToIndirectStar(vector<vector<int>> adjMatrix);
    void indirectStarToAdjMatrix(/*Dont know*/);
    void dfs(Digraph d, string v);
    void application();
  };
} // namespace sml

#endif //OPERATIONS_H
