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
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::stoi;
using std::string;

#include <utility>
using std::pair;
using std::make_pair;
namespace sml {
    class Graph
    {
    private:
        int numNodes;
        map<int, vector<int>> adjList; //!< The adjacency list that represents the graph;
        vector<vector<int>> adjMatrix; //!< The adjacency matrix that represents the graph;
        vector<vector<int>> incMatrix; //!< The incidence matrix that represents the graph;

        //Printing functions
        void printAdjList();
        void printAdjMatrix();
        void printIncMatrix();

        //Modification functions
        void addVertex(int x);
        void addEdge(pair<int, int> x);

        void removeVertex(int x);
        void removeEdge(pair<int,int> x);

        int manageVertex();
        pair<int,int> manageEdge();

        //Menu
        void pause();
        void displayMenu();

    public:
        //Contructors
        Graph();
        Graph(int numNodes);

        //Get methods
        map<int,vector<int>> getAdjList();
        vector<vector<int>> getAdjMatrix();
        vector<vector<int>> getIncMatrix();
        int getNumNodes();
        
        //Update(set) methods
        void updateAdjList(map<int, vector<int>> adjList);
        void updateAdjMatrix(vector<vector<int>> adjMatrix);
        void updateIncMatrix(vector<vector<int>> incMatrix);
        
        //Menu
        void manageMenu();
    };    
}

#endif //GRAPH_H