#include "simulation.h" 
#include <vector>
#include <limits>
#include <iostream>

using namespace sml;

/**!
 * Esta função implementa o algoritmo de Floyd-Warshall para encontrar as distâncias mínimas entre todos os pares de vértices
 * de um grafo ponderado. O algoritmo atualiza a matriz de distâncias e a matriz de predecessores para reconstrução de caminhos.
 * 
 * @param g Grafo no qual serão calculadas as distâncias mínimas entre os vértices
 */
void Simulation::floydWarshall() {
    const int INF = std::numeric_limits<int>::max();  // Define o valor de infinito

    int n = this->graph.n;  // Número de vértices no grafo
    std::vector<std::vector<int>> adj = this->graph.adj;  // Matriz de adjacência
    std::vector<std::vector<int>> dist(n, std::vector<int>(n, INF));  // Matriz de distâncias
    std::vector<std::vector<int>> pred(n, std::vector<int>(n, -1));  // Matriz de predecessores

    // Inicializa as distâncias e predecessores
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (adj[i][j] != 0) {  
                dist[i][j] = adj[i][j];
                pred[i][j] = i;  
            }
            if (i == j) {
                dist[i][j] = 0;  
                pred[i][j] = i;  
            }
        }
    }

    // Algoritmo de Floyd-Warshall
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // Se passar por k melhora a distância, atualiza distancia e predecessor
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pred[i][j] = pred[k][j];
                }
            }
        }
    }

    // Exibe as distâncias mínimas
    std::cout << " Matriz de distâncias mínimas entre os vertices:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF) {
                std::cout << "INF ";  // Exibe INF para distâncias infinitas
            } else {
                std::cout << dist[i][j] << " "; 
            }
        }
        std::cout << std::endl;
    }

    // Exibe os predecessores
    std::cout << " Matriz de predecessores para reconstrucao de caminhos:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << pred[i][j] << " "; 
        }
        std::cout << std::endl;
    }
}