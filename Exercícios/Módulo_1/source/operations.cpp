#include "operations.hpp"

using namespace sml;

vector<vector<int>> Operations::adjListToAdjMatrix(map<int, vector<int>> adjList, int numNodes)
{
    /*TO-DO*/
}

map<int, vector<int>> Operations::adjMatrixToAdjList(vector<vector<int>> adjMatrix, int numNodes)
{
    /*TO-DO*/
}

void Operations::calculateDegrees(Graph g)
{
}

void Operations::adjacentsVertex(Graph g, int u, int v)
{
    /*TO-DO*/
}

int Operations::countVertices(Graph g)
{
    /*TO-DO*/
}

int Operations::countEdges(Graph g)
{
    /*TO-DO*/
}

bool Operations::connected(Graph g)
{
    /*TO-DO*/
}

bool Operations::bipartite(Graph g)
{
    /*TO-DO*/
}

void Operations::dfs(Graph g, int v)
{
    auto numNodes = g.getNumNodes();

    auto adjList = g.getAdjList();

    vector<bool> visited = vector(numNodes, false);
    vector<int> pred = vector(numNodes, -1);
    stack<int> s;

    visited[v] = true;
    s.push(v);

    while (!s.empty())
    {
        int curr = s.top();
        s.pop();

        for (auto edge : adjList[v])
        {
            if (!visited[edge])
            {
                visited[edge] = true;
                pred[edge] = v;
                s.push(edge);
            }
        }
    }
}
void Operations::bfs(Graph g, int v)
{
    /*TO-DO*/
}

void Operations::articulationsAndBlocks(Graph g)
{
    /*TO-DO*/
}

// THE MATH AND SEARCH OPERATIONS FROM DIGRAPHS
void Operations::subjacenteGraph(Digraph d)
{
    /*TO-DO*/
}

void Operations::incMatrixToDirectStar(vector<vector<int>> incMatrix, int numNodes)
{
    /*TO-DO*/
}

vector<vector<int>> Operations::directStarToIncMatrix(/*Dont know*/)
{
    /*TO-DO*/
}

void Operations::adjMatrixToIndirectStar(vector<vector<int>> adjMatrix, int numNodes)
{
    /*TO-DO*/
}

vector<vector<int>> Operations::indirectStarToAdjMatrix(/*Dont know*/)
{
    /*TO-DO*/
}

void Operations::dfs(Digraph d)
{
    /*TO-DO*/
}

void Operations::application()
{
    /*TO-DO*/
}
