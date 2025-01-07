#include "simulation.h"
#include <algorithm>
#include <vector>

using namespace sml;

#define MAXN 1000
static int parent[MAXN];
static int rank_set[MAXN];

static void init(size_t n) {
    for(size_t i = 0; i < n; i++) {
        parent[i] = i;
        rank_set[i] = 1;
    }
}

static size_t find(size_t cur) {
    size_t root = cur;
    
    while(parent[root] != root)
        root = parent[root];
    
    //Path compression
    while(parent[cur] != root) {
        size_t temp = parent[cur];
        parent[cur] = root;
        cur = temp;
    }
    
    return root;
}

static void join(size_t x, size_t y) {
    x = find(x);
    y = find(y);
    
    if(x == y) return;
    
    if(rank_set[x] > rank_set[y]) std::swap(x, y);
    rank_set[y] += rank_set[x];
    parent[x] = y;
}

void Simulation::kruskal(void) {
    //Converter matriz de adjacência para lista de arestas
    std::vector<std::pair<int, std::pair<size_t, size_t>>> edges;
    
    for(size_t i = 0; i < graph.n; i++) {
        for(size_t j = i + 1; j < graph.n; j++) {
            if(graph.adj[i][j] != -1) {
                edges.push_back({graph.adj[i][j], {i, j}});
            }
        }
    }
    
    //Inicializar estruturas
    init(graph.n);
    sort(edges.begin(), edges.end());
    
    //Resultado da MST
    std::vector<std::pair<int, std::pair<size_t, size_t>>> mst;
    int total_weight = 0;
    
    //Algoritmo de Kruskal
    for(const auto& edge : edges) {
        size_t u = edge.second.first;
        size_t v = edge.second.second;
        
        if(find(u) != find(v)) {
            join(u, v);
            mst.push_back(edge);
            total_weight += edge.first;
        }
    }
    
    //Imprimir resultado
    std::cout << "\nArvore Geradora Minima encontrada pelo algoritmo de Kruskal:\n";
    std::cout << "Arestas da MST:\n";
    for(const auto& edge : mst) {
        std::cout << graph.dictionary[edge.second.first] << " -- " 
                 << graph.dictionary[edge.second.second] << " : "
                 << edge.first << "\n";
    }
    std::cout << "Peso total da MST: " << total_weight << "\n";
}