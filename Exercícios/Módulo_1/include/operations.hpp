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
using std::cout;
using std::endl;

#include "digraph.hpp"
#include "graph.hpp"

namespace sml {
struct SearchResult {
  int numNodes;
  int initialNode;
  vector<int> predecessors;
  vector<bool> visited;

  friend std::ostream &operator<<(std::ostream &os,
                                  const SearchResult &result) {
    os << std::left; // Align to the left

    // Print header
    os << std::setw(15) << "Node" << std::setw(15) << "Visited" << std::setw(15)
       << "Predecessor" << '\n';

    // Print separator
    os << std::setfill('-') << std::setw(45) << "" << std::setfill(' ') << '\n';

    // Print each node's information
    for (int i = 1; i <= result.numNodes; ++i) {
      os << std::setw(15) << i                      // Node number
         << std::setw(15) << result.visited[i]      // Visited status
         << std::setw(15) << result.predecessors[i] // Predecessor
         << '\n';
    }

    return os;
  }
};

class Operations {
public:
  // THE MATH AND SEARCH OPERATIONS FROM GRAPHS
  vector<vector<int>> adjListToAdjMatrix(map<int, vector<int>> adjList,
                                         int numNodes);

  map<int, vector<int>> adjMatrixToAdjList(vector<vector<int>> adjMatrix,
                                           int numNodes);

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
  void subjacenteGraph(Digraph d);

  void incMatrixToDirectStar(vector<vector<int>> incMatrix, int numNodes);
  vector<vector<int>> directStarToIncMatrix(/*Dont know*/);

  void adjMatrixToIndirectStar(vector<vector<int>> adjMatrix, int numNodes);

  vector<vector<int>> indirectStarToAdjMatrix(/*Dont know*/);

  void dfs(Digraph d);

  void application();
};
} // namespace sml

#endif // OPERATIONS_H
