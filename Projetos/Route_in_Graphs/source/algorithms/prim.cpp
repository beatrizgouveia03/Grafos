#include "simulation.h"
#include <limits>
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace sml;

/**!
 * Esta função implementa o algoritmo de Prim para encontrar a Árvore Geradora Mínima (AGM) de um grafo.
 * O algoritmo começa em um vértice e vai adicionando as arestas de menor peso que conectam o conjunto Z 
 * de vértices já incluídos à árvore, ao conjunto V de vértices restantes.
 * 
 * @param g Grafo no qual será calculada a Árvore Geradora Mínima
 */
void Simulation::prim() {
    const int INF = std::numeric_limits<int>::max();  // Define o valor de infinito

    int n = this->graph.n;  // Número de vértices no grafo
    std::vector<std::vector<int>> adj = this->graph.adj;  // Matriz de adjacência
    std::map<int, std::string> dictionary = this->graph.dictionary;  // Mapeamento dos vértices

    std::set<int> Z;  // Conjunto de vértices já incluídos na AGM
    std::set<int> V;  // Conjunto de vértices restantes

    Z.insert(0);  // Escolhe o vértice inicial (índice 0)
    for (int i = 1; i < n; ++i) {
        V.insert(i);  // Inicializa o conjunto V
    }

    std::vector<std::pair<int, int>> TMin;  // Conjunto das arestas da AGM

    // Algoritmo de Prim
    while (Z.size() != n) {  // Enquanto nem todos os vértices forem incluídos
        int minWeight = INF;  // Peso mínimo das arestas
        int j = -1, k = -1;

        // Busca pela aresta de peso mínimo que conecta Z a V
        for (int u : Z) {
            for (int v : V) {
                if (adj[u][v] != 0 && adj[u][v] < minWeight) {  // Ignora arestas sem conexão
                    minWeight = adj[u][v];
                    j = u;
                    k = v;
                }
            }
        }

        if (j != -1 && k != -1) {
            Z.insert(k);  // Adiciona k à AGM
            V.erase(k);   // Remove k de V
            TMin.push_back({j, k});  // Adiciona a aresta (j, k) à AGM
        } else {
            std::cout << "Erro: Grafo desconexo." << std::endl;  // Caso o grafo seja desconexo
            return;
        }
    }

    // Exibe as arestas da Árvore Geradora Mínima
    std::cout << "Arestas da Árvore Geradora Mínima:" << std::endl;
    int totalWeight = 0;  // Peso total da árvore
    for (const auto &edge : TMin) {
        int j = edge.first;
        int k = edge.second;
        std::cout << dictionary[j] << " - " << dictionary[k]
                  << " (Peso: " << adj[j][k] << ")" << std::endl;
        totalWeight += adj[j][k];  // Atualiza o peso total
    }
    std::cout << "Peso total da AGM: " << totalWeight << std::endl;
}

