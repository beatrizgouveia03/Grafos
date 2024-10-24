#ifndef GRAPH_H
#define GRAPH_H

/*!
 * @file graph.hpp
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

namespace sml {
    class Graph
    {
    private:
        int numNodes;
        map<int, vector<int>> adjList; //!< The adjacency list that represents the graph;
        vector<vector<int>> adjMatrix; //!< The adjacency matrix that represents the graph;
        vector<vector<int>> incMatrix; //!< The incidence matrix that represents the graph;
    public:
        //Contructors
        Graph();
        Graph(int numNodes);

        //Printing functions
        void printGraphAsAdjList();
        void printGraphAsAdjMatrix();
        void printGraphAsIncMatrix();

        //Get methods
        map<int,vector<int>> getAdjList();
        vector<vector<int>> getAdjMatrix();
        vector<vector<int>> getIncMatrix();
        int getNumNodes();
        
        //Update(set) methods
        void updateAdjList(map<int, vector<int>> adjList);
        void updateAdjMatrix(vector<vector<int>> adjMatrix);
        void updateIncMatrix(vector<vector<int>> incMatrix);

        //Modification functions
        void addVertex();
        void addEdge(int u, int v);

        void removeVertex(int u);
        void removeEdge(int u, int v);

        //Other functios
        /* ADD HERE THE REST OF THE GRAPH FUNCTIONS*/
    };    
}

#endif //GRAPH_H