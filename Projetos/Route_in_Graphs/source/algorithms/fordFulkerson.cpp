#include "simulation.h"

using namespace sml;

const int INF = numeric_limits<int>::max();

bool dfs(int n, vector<vector<int>>& residualG, int s, int t, vector<int>& parent){
	vector<bool> visited(n, false);
	stack<int> st;

	visited[s] = true;
	st.push(s);

	while(!st.empty()){
		int top = st.top();
		st.pop();

		for(int i = 0; i < n; i++){
			if(!visited[i] && residualG[top][i] > 0){
				st.push(i);
				visited[i] = true;
				parent[i] = top;
				if(i == t) return true;
			}
		}
	}
	return false;
}

void Simulation::fordFulkerson(void) {
        int initial = 0;
        int numNodes = this->graph.n;
        std::vector<std::vector<int>> residualG = this->graph.adj;
				vector<int> parent(numNodes, -1);
        int max_flow = 0;
        int s = 0;
        int t = numNodes - 1;
        int u;

        while (dfs(this->graph.n, residualG, s, t, parent)) {
            int path_flow = INF;
            for (int i = t; i != s; i = parent[i]) {
                u = parent[i];
                path_flow = std::min(path_flow, residualG[u][i]);
            }
            for (int i = t; i != s; i = parent[i]) {
                u = parent[i];
                residualG[u][i] -= path_flow;
                residualG[i][u] += path_flow;
            }
            max_flow += path_flow;
        }

        std::cout << "Ford-Fulkerson: " << max_flow << std::endl;
        
    }
