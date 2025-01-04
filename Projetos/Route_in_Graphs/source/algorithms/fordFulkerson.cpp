#include "simulation.h"

using namespace sml;

const int INF = std::numeric_limits<int>::max();

bool _bfs(int n, vector<vector<int>> residualG, int s, int t, int parent[]){
	vector<bool> visited(n);

	queue<int> q;

	q.push(s);
	visited[s] = true;
	parent[s] = -1;

	while(!q.empty()){
		int curr = q.front();
		q.pop();

		for(int i = 0; i < n; i++){
			if(!visited[i] && residualG[curr][i] > 0 && residualG[curr][i] != INF){
				if(i == t){
					parent[i] = curr;
					return true;
				}

				q.push(i);
				parent[i] = curr;
				visited[i] = true;
			}
		}
	}

	return false;
}

void Simulation::fordFulkerson (void){
		int initial = 0;
		int numNodes = this->graph.n;

		vector<vector<int>> residualG = this->graph.adj;


		int* parent = new int[numNodes];
		int max_flow = 0;

		int s = 0;
		int t = numNodes-1;
		int u;

		while(_bfs(this->graph.n, residualG, s, t, parent)){
			int path_flow = INF;

			for(int i = t; i != s;i = parent[i]){
				u = parent[i];
				path_flow = std::min(path_flow, residualG[u][i]);
			};

			for(int i = t; i != s; i = parent[i]){
				u = parent[i];
				residualG[u][i] -= path_flow;
				residualG[i][u] += path_flow;
			};

			max_flow += path_flow;
		}

    cout << "Ford-Fulkerson: " << max_flow << endl;
};
