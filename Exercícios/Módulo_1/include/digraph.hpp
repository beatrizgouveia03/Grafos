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
    class Digraph
    {
        //== Private Members
        private:
            int numNodes;                  //!< The amount of vertices of the digraph;
            map<int, string> dictionary;     //!< The list that keeps the name of each vertex;
            map<int, vector<int>> adjList; //!< The adjacency list that represents the digraph;
            vector<vector<int>> adjMatrix; //!< The adjacency matrix that represents the digraph;
            vector<vector<int>> incMatrix; //!< The incidence matrix that represents the digraph;

        //== Public Members
        public:
            Digraph(void);
            Digraph(int numNodes);
            int getNumNodes(void);
            map<int, string> getDictionary(void);
            map<int,vector<int>> getAdjList(void);
            vector<vector<int>> getAdjMatrix(void);
            vector<vector<int>> getIncMatrix(void);
            void updateDictionary(map<int, string> dictionary);
            void updateAdjList(map<int, vector<int>> adjList);
            void updateAdjMatrix(vector<vector<int>> adjMatrix);
            void updateIncMatrix(vector<vector<int>> incMatrix);
            void runMenu(void);

        //== Aux Members
        private:
            void pause(void);
            void displayMenu(void);
            void printAdjList(void);
            void printAdjMatrix(void);
            void printIncMatrix(void);
            void addVertex(int x);
            void addEdge(pair<int,int> x);
            void removeVertex(int x);
            void removeEdge(pair<int,int> x);
            int manageVertex(void);
            pair<int,int> manageEdge(void);
    };    
}

#endif // DIGRAPH_H