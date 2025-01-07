#include "simulation.h" 

using namespace sml;

/**!
 * Esta função implementa o algoritmo de Floyd-Warshall para encontrar as distâncias mínimas entre todos os pares de vértices
 * de um grafo ponderado. O algoritmo atualiza a matriz de distâncias e a matriz de predecessores para reconstrução de caminhos.
 * 
 * @param g Grafo no qual serão calculadas as distâncias mínimas entre os vértices
 */
void Simulation::floydWarshall() {
    const int INF = numeric_limits<int>::max();  // Define o valor de infinito

    int n = this->graph.n;  // Número de vértices no grafo
    vector<vector<int>> adj = this->graph.adj;  // Matriz de adjacência
    vector<vector<int>> dist(n, vector<int>(n, INF));  // Matriz de distâncias
    vector<vector<int>> pred(n, vector<int>(n, -1));  // Matriz de predecessores
    map<int, string> dic = this->graph.dictionary;    // Lista que mantém o nome de cada vértice

    // Inicializa as distâncias e predecessores
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (adj[i][j] != -1) {  
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
    cout << "Matriz de distancias minimas entre os vertices:" << endl << endl;
  // cout << "      ";

  // for (int i = 0; i < n; i++)
  // {
  //     cout << i+1;
  //     if(i+1 < 10) cout << " ";
  //     cout << " ";
  // }
  // cout << endl;

  // for (int i = 0; i < n; ++i) {
  //     if(i+1 < 10) cout << " ";
  //     cout << i+1 << " ";

  //     for (int j = 0; j < n; ++j) {
  //         if (dist[i][j] == INF) {
  //             cout << "INF ";  // Exibe INF para distâncias infinitas
  //         } else {
  //             cout << " ";
  //             if(dist[i][j] < 10 && dist[i][j] >= 0) cout << " ";
  //             cout << dist[i][j] << " "; 
  //         }
  //     }
  //     cout << endl;
  // }
   
    cout << "  \\  "; 
    for (int i{0}; i<n; ++i) {
      if(dic[i].length() == 1) cout << " ";
      cout << dic[i] <<"  ";
    }
    cout << endl;

    cout << "    ";
    for (int i{0}; i<n; ++i) {
      cout << "____";
    }
    cout << endl;

    for(int i{0}; i<n; ++i){
      if(dic[i].length() == 1) cout << " ";
      cout << dic[i] << "| ";
      for(int j{0}; j<n; ++j){
        if (dist[i][j] == INF) {
            cout << "INF ";  // Exibe INF para distâncias infinitas
        } else {
            if(dist[i][j] < 10) cout << "  ";
            else if(dist[i][j] < 100) cout << " ";
            cout << dist[i][j] << " ";
        }
      }
      cout << endl;
    }
    cout << endl;

    // Exibe os predecessores
    cout << "Matriz de predecessores para reconstrucao de caminhos:" << endl << endl;
    //cout << "   ";
    //
    //for (int i = 0; i < n; i++)
    //{
    //    cout << i+1;
    //    if(i+1 < 10) cout << " ";
    //    cout << " ";
    //}
    //cout << endl;
//
    //for (int i = 0; i < n; ++i) {
    //    if(i+1 < 10) cout << " ";
    //    cout << i+1 << " ";
//
    //    for (int j = 0; j < n; ++j) {
    //        if(pred[i][j] < 10 && pred[i][j] >= 0) cout << " ";
    //        cout << pred[i][j] << " "; 
    //    }
    //    cout << endl;
    //}
    cout << "  \\  "; 
    for (int i{0}; i<n; ++i) {
      if(dic[i].length() == 1) cout << " ";
      cout << dic[i] <<"  ";
    }
    cout << endl;

    cout << "    ";
    for (int i{0}; i<n; ++i) {
      cout << "____";
    }
    cout << endl;

    for(int i{0}; i<n; ++i){
      if(dic[i].length() == 1) cout << " ";
      cout << dic[i] << "| ";
      for(int j{0}; j<n; ++j){
        if(pred[i][j] < 10 && pred[i][j]>=0) cout << "  ";
        else if(pred[i][j] < 100) cout << " ";
        cout << pred[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
}