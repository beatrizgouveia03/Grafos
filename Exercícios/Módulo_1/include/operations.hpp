#ifndef OPERATIONS_H
#define OPERATIONS_H

/*!
 * @file operations.hpp
 * @author Beatriz Gouveia
 * @date Oct 22nd, 2024
*/

#include <map>
using std::map;

#include <vector>
using std::vector;

#include <stack>
using std::stack;

#include <iostream>
using std::cout;
using std::endl;

#include "graph.hpp"
#include "digraph.hpp"

namespace sml {
    class Operations
    {
    public:
        //THE MATH AND SEARCH OPERATIONS FROM GRAPHS
        vector<vector<int>> adjListToAdjMatrix(map<int, vector<int>> adjList, int numNodes);

        map<int, vector<int>> adjMatrixToAdjList(vector<vector<int>> adjMatrix, int numNodes);

        void calculateDegrees(Graph g);

        void adjacentsVertex(Graph g, int u, int v);

        int countVertices(Graph g);

        int countEdges(Graph g);

        bool connected(Graph g);

        bool bipartite(Graph g);

        void dfs(Graph g, int v);

        void bfs(Graph g, int v);

        void articulationsAndBlocks(Graph g);

        //THE MATH AND SEARCH OPERATIONS FROM DIGRAPHS
        void subjacenteGraph(Digraph d);

        void incMatrixToDirectStar(vector<vector<int>> incMatrix, int numNodes);

        vector<vector<int>> directStarToIncMatrix(/*Dont know*/);

        void adjMatrixToIndirectStar(vector<vector<int>> adjMatrix, int numNodes);

        vector<vector<int>> indirectStarToAdjMatrix(/*Dont know*/);

        void dfs(Digraph d);

        void application();

    };    
}

#endif //OPERATIONS_H