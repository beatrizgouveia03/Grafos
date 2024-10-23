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
        void adjListToAdjMatrix(map<int, vector<int>> adjList);

        void adjMatrixToAdjList(vector<vector<int>> adjMatrix);

        void calculateDegrees(Graph g);

        void adjacentsVertex(Graph g, int u, int v);

        void countVertices(Graph g);

        void countEdges(Graph g);

        void connected(Graph g);

        void bipartite(Graph g);

        void dfs(Graph g, int v);

        void bfs(Graph g, int v);

        void articulationsAndBlocks(Graph g);

        //THE MATH AND SEARCH OPERATIONS FROM DIGRAPHS
        void subjacenteGraph(Digraph d);

        void incMatrixToDirectStar(vector<vector<int>> digraphIncMatrix);

        void directStarToIncMatrix(/*Dont know*/);

        void adjMatrixToIndirectStar(vector<vector<int>> digraphAdjMatrix);

        void indirectStarToAdjMatrix(/*Dont know*/);

        void dfs(Digraph d);

        void application();

    };    
}

#endif //OPERATIONS_H