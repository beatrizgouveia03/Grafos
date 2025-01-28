#include "simulation.h"

using namespace sml;

// Função auxiliar para verificar se é um ciclo hamiltoniano (todos os vértices foram visitados)
bool isAHamiltonianCycle(const vector<bool> &visited)
{
  for (bool v : visited)
  {
    if (!v)
      return false;
  }
  return true;
}

pair<double, vector<int>> Simulation::tspGreedy(int numCities)
{
  cout << "Algoritmo Guloso" << endl;

  const vector<vector<double>> distMatrix = this->graph.adj;
  vector<bool> visitedCities(numCities, false);
  vector<int> finalPath;
  double cost = 0;

  // início no vertice 0
  int current = 0;
  visitedCities[current] = true;
  finalPath.push_back(current);

  while (!isAHamiltonianCycle(visitedCities))
  {
    // Encontrar o vizinho mais próximo não visitado
    int nearest = -1; 
    int minDist = INT_MAX;

    for (int i = 0; i < numCities; i++)
    {
      if (!visitedCities[i] && distMatrix[current][i] < minDist)
      {
        minDist = distMatrix[current][i];
        nearest = i;
      }
    }

    // Adicionar o custo da aresta
    cost += distMatrix[current][nearest];

    visitedCities[nearest] = true;
    finalPath.push_back(nearest);

    // Atualizar o vértice atual
    current = nearest;
  }

  cout << "Caminho final: ";
  for (int v : finalPath)
  {
    cout << v + 1 << " ";
  }
  cout << endl;
  cout << "Custo total: " << cost << endl;

  return pair<double, vector<int>>(cost, finalPath);
}