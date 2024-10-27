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
  private:
    Graph graph;
    Digraph digraph;

    // THE MATH AND SEARCH OPERATIONS FROM GRAPHS
    vector<vector<int>> adjListToAdjMatrix(map<int, vector<int>> adjList, int numNodes);

    map<int, vector<int>> adjMatrixToAdjList(vector<vector<int>> adjMatrix, int numNodes);

    void calculateDegrees(Graph g);

    void adjacentsVertex(Graph g, int u, int v);

    int countVertices(Graph g);

    int countEdges(Graph g);

    bool connected(Graph g);

    bool bipartite(Graph g);

    SearchResult dfs(Graph g, int v);

    void bfs(Graph g, int v);

    void articulationsAndBlocks(Graph g);

    // THE MATH AND SEARCH OPERATIONS FROM DIGRAPHS
    void subjacentGraph(Digraph d);

    void incMatrixToDirectStar(vector<vector<int>> incMatrix, int numNodes);

    vector<vector<int>> directStarToIncMatrix(/*Dont know*/);

    void adjMatrixToIndirectStar(vector<vector<int>> adjMatrix, int numNodes);

    vector<vector<int>> indirectStarToAdjMatrix(/*Dont know*/);

    void dfs(Digraph d, int v);

    void application();

    //Menu
    void pause();
    void displayMenu();
    
  public:
    //Constructors
    Operations();
    Operations(Graph g, Digraph d);


    //Menu
    void runMenu();

    //Update(set) methods
    void updateGraph();
    void updateDigraph();
  };
} // namespace sml

#endif // OPERATIONS_H
