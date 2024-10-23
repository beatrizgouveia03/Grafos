#ifndef DIGRAPH_H
#define DIGRAPH_H

/*!
 * @file digraph.hpp
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
    class Digraph
    {
    private:
        int numNodes;
        map<int, vector<int>> adjList; //!< The adjacency list that represents the graph;
        vector<vector<int>> adjMatrix; //!< The adjacency matrix that represents the graph;
        vector<vector<int>> incMatrix; //!< The incidence matrix that represents the graph;
    public:
        //Contructors
        Digraph();
        Digraph(int numNodes);

        //Printing methods
        void printDigraphAsAdjList();
        void printDigraphAsAdjMatrix();
        void printDigraphAsIncMatrix();

        //Get methods
        map<int,vector<int>> getAdjList();
        vector<vector<int>> getAdjMatrix();
        vector<vector<int>> getIncMatrix();

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
        /* ADD HERE THE REST OF THE DIGRAPH FUNCTIONS*/
    };    
}

#endif // DIGRAPH_H