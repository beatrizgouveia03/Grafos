#include "simulation.h"

using namespace sml;

struct Edge {
    int from, to, weight;
    Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
};

pair<bool, vector<int>> findCycle(vector<vector<int>>& graph, int n) {
    vector<bool> visited(n, false);
    vector<bool> inStack(n, false);
    vector<int> cycle;
    
    for (int start = 0; start < n; start++) {
        if (visited[start]) continue;
        
        stack<pair<int, int>> st;
        vector<int> path;
        st.push({start, 0});
        inStack[start] = true;
        path.push_back(start);
        
        while (!st.empty()) {
            int current = st.top().first;
            int& neighborIndex = st.top().second;
            
            visited[current] = true;
            
            bool foundNext = false;
            for (; neighborIndex < n; neighborIndex++) {
                if (graph[current][neighborIndex] > 0) {
                    if (!visited[neighborIndex]) {
                        st.push({neighborIndex, 0});
                        inStack[neighborIndex] = true;
                        path.push_back(neighborIndex);
                        foundNext = true;
                        break;
                    }
                    else if (inStack[neighborIndex]) {
                        auto it = find(path.begin(), path.end(), neighborIndex);
                        cycle = vector<int>(it, path.end());
                        return {true, cycle};
                    }
                }
            }
            
            if (!foundNext) {
                inStack[current] = false;
                path.pop_back();
                st.pop();
            }
        }
    }
    return {false, cycle};
}

void Simulation::chuLiuEdmonds(void) {
    int n = this->graph.n;
    int root = 1;
    vector<vector<int>> adj = this->graph.adj;
    vector<bool> visited(n, false);
    vector<Edge> s;
    
    auto findMinIncoming = [&](int vertex) -> pair<int, int> {
        int min_weight = INT_MAX;
        int min_from = -1;
        for(int i = 0; i < n; i++) {
            if(i != vertex && adj[i][vertex] > 0 && adj[i][vertex] < min_weight) {
                min_weight = adj[i][vertex];
                min_from = i;
            }
        }
        return {min_from, min_weight};
    };

    /* Passo 1:
     * Descarte os arcos que entram na raiz, se houver; Para cada nó
     * diferente da raiz, selecione o arco de entrada com o menor custo;
     * Defina os n-1 arcos selecionados como o conjunto S.
     */
    for(int i = 0; i < n; i++) {
        if(i != root) {
            auto [min_from, min_weight] = findMinIncoming(i);
            if(min_from != -1) {
                s.push_back(Edge(min_from, i, min_weight));
            }
        }
    }

    // Passo 2
    while(true) {
        vector<vector<int>> cycle_graph(n, vector<int>(n, 0));
        for(const Edge& e : s) {
            cycle_graph[e.from][e.to] = e.weight;
        }
        auto [hasCycle, cycle] = findCycle(cycle_graph, n);

        // Se nenhum ciclo for formado, G = (N, S) é uma árvore geradora mínima
        if(!hasCycle) break;

        // Caso contrário, continue
        vector<bool> inCycle(n, false);
        for(int v : cycle) inCycle[v] = true;
        
        // Passo 3:  Contrai o ciclo em um pseudo nó
        int cycle_id = cycle[0];
        vector<Edge> new_s;
        
        for(const Edge& e : s) {
            if(!inCycle[e.from] || !inCycle[e.to]) {
                if(inCycle[e.to]) {
                    new_s.push_back(Edge(e.from, cycle_id, e.weight));
                } else if(inCycle[e.from]) {
                    new_s.push_back(Edge(cycle_id, e.to, e.weight));
                } else {
                    new_s.push_back(e);
                }
            }
        }

        int min_weight = INT_MAX;
        Edge* min_edge = nullptr;
        for(Edge& e : s) {
            if(!inCycle[e.from] && inCycle[e.to] && e.weight < min_weight) {
                min_weight = e.weight;
                min_edge = &e;
            }
        }

        /* Passo 4: 
         * Para cada pseudo-nó, selecione o arco de entrada que tem o menor custo modificado; 
         * Substitua o arco que entra no mesmo nó real em S pelo novo arco selecionado.
         */
        if(min_edge != nullptr) {
            new_s.push_back(*min_edge);
            for(const Edge& e : s) {
                if(inCycle[e.from] && inCycle[e.to] && e.from != min_edge->to) {
                    new_s.push_back(e);
                }
            }
        }

        s = new_s;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    for(const Edge& e : s) {
        adj[e.from][e.to] = e.weight;
    }

    this->graph.adj = adj;

		cout << "Grafo novo gerado: " << endl;
		cout << this->graph;
}
