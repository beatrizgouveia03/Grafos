#include "simulation.h"
#include <queue>
#include <limits>

using namespace sml;

void Simulation::dijkstra(void) {

    const int INF = numeric_limits<int>::max();
    std::string str;
    std::cout << "Digite o vertice inicial: ";
    std::getline(std::cin, str);
    
    //Encontrar o índice do vértice inicial no dicionário
    size_t start = 0;
    for(const auto& pair : graph.dictionary) {
        if(pair.second == str) {
            start = pair.first;
            break;
        }
    }
    
    //Inicialização
    std::vector<int> dist(graph.n, INF);
    std::vector<int> parent(graph.n, -1);
    std::vector<bool> visited(graph.n, false);
    
    //Fila de prioridade para escolher o vértice mais próximo
    //pair: {distância, vértice}
    std::priority_queue<
        std::pair<int, int>,
        std::vector<std::pair<int, int>>,
        std::greater<std::pair<int, int>>
    > pq;
    
    //Inicializar distância do vértice inicial
    dist[start] = 0;
    pq.push(std::make_pair(0, start));
    
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        if(visited[u]) continue;
        visited[u] = true;
        
        //Para cada vértice adjacente
        for(size_t v = 0; v < graph.n; v++) {
            if(graph.adj[u][v] == -1) continue; // Se não há aresta
            
            //Se encontrou um caminho mais curto
            if(!visited[v] && dist[u] != INF && 
               dist[u] + graph.adj[u][v] < dist[v]) {
                dist[v] = dist[u] + graph.adj[u][v];
                parent[v] = u;
                pq.push(std::make_pair(dist[v], v));
            }
        }
    }
    
    //Imprimir resultados
    std::cout << "\nResultados do algoritmo de Dijkstra a partir do vertice " 
              << graph.dictionary[start] << ":\n\n";
         
    for(size_t i = 0; i < graph.n; i++) {
        if(i == start) continue;
        
        std::cout << "Distancia ate " << graph.dictionary[i] << ": ";
        if(dist[i] == INF) {
            std::cout << "INF (não alcançável)\n";
            continue;
        }
        std::cout << dist[i] << "\n";
        
        //Imprimir o caminho
        std::cout << "Caminho: ";
        std::vector<int> path;
        int current = i;
        while(current != -1) {
            path.push_back(current);
            current = parent[current];
        }
        
        for(int j = path.size() - 1; j >= 0; j--) {
            std::cout << graph.dictionary[path[j]];
            if(j > 0) std::cout << " -> ";
        }
        std::cout << "\n\n";
    }
}