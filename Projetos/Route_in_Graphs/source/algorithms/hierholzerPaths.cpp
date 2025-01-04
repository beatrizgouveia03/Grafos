#include "simulation.h"

using namespace sml;

void Simulation::hierholzerPaths (void){
    int n = this->graph.n;                     //!< Número de vértices
    vector<vector<int>> aux = this->graph.adj; //!< Matriz auxilia
    vector<int> in(n, 0), out(n, 0);           //!< Vetores de graus de entrada e saída

    // Calcular graus de entrada e saída
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            in[j] += aux[i][j];
            out[i] += aux[i][j];
        }   
    }
    
    // Calcular graus de cada vértice
    vector<int> degrees(n, 0);                  //!< Vetor de graus
    for (int i = 0; i < n; i++) {
        degrees[i] = in[i] - out[i];
    }

    // Verifica se o grafo é euleriano
    if(degrees[0] != 1 || degrees[n-1] != -1){
        cout << "Não há caminho euleriano." << endl;
        return;
    }

    // Verificar a condição de existência de um caminho euleriano em um digrafo
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (degrees[i] != 0) {
            count++;
            break;
        }
    }

    if (count > 2) {
        cout << "Não há caminho euleriano." << endl;
        return;
    }

    // Inicializar pilha para armazenar caminho euleriano


};

