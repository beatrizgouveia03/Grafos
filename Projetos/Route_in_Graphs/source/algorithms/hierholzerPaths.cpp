#include "simulation.h"

using namespace sml;

void Simulation::hierholzerPaths (void){
    int n = this->graph.n;                     //!< Número de vértices
    vector<vector<int>> aux = this->graph.adj; //!< Matriz auxilia
    vector<int> in(n, 0), out(n, 0);           //!< Vetores de graus de entrada e saída

    // Calcular graus de entrada e saída
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (aux[i][j] > 0) ? out[i] += aux[i][j], in[j] += aux[i][j] : 0;
        }   
    }
    
    // Calcular graus de cada vértice
    vector<int> degrees(n, 0);                  //!< Vetor de graus
    for (int i = 0; i < n; i++) {
        degrees[i] = out[i] - in[i];
    }

    // Testando tabela de graus
    cout << "Tabela de graus: " << endl;
    for(auto i{0}; i<n; ++i){
        cout << "Vértice" << i+1 << " : " << degrees[i] << endl; 
    }


    // Verificar a condição de existência de um caminho euleriano em um digrafo
    int start = 0, end = n - 1; // Vértices de início e fim (1 e 19)

    if (degrees[start] != 1 || degrees[end] != -1) {
        cout << "Nao ha caminho euleriano: grau de origem ou destino inválido" << endl;
        return;
    }

    for (int i = 1; i < n-1; i++) {
        if (degrees[i] != 0) {
            cout << "Nao ha caminho euleriano: grau de vértice interno impar." << endl;
            break;
        }
    }

    // Inicializar pilha para armazenar caminho euleriano
    vector<int> eulerianPath;            //!< Vetor para armazenar o caminho euleriano

    //1. Escolher um vértice v de G
    int v = 0;                                  //!< Vértice inicial
    eulerianPath.push_back(v);                  //!< Adiciona o vértice inicial ao caminho euleriano

    //2. Construir uma cadeia fechada C, a partir de v, percorrendo as arestas de G
    //aleatoriamente.
    while (true) {
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (aux[v][i] >= 0) {
                flag = true;
                eulerianPath.push_back(i);
                aux[v][i] = -1;
                v = i;
                break;
            }
        }
        if (!flag) {
            break;
        }
    }

    //3. Remover de G as arestas de C
    for (int i = 0; i < eulerianPath.size() - 1; i++) {
        aux[eulerianPath[i]][eulerianPath[i + 1]] = 0;
        degrees[eulerianPath[i]]--;
        degrees[eulerianPath[i + 1]]++;
    }

    //4. Enquanto (M ≠ Ø) Fazer
    while (true) {
        bool flag = false;

        //5. Escolher v tal que d(v) > 0 e v ∈ C
        for (int i = 0; i < n; i++) {
            if (degrees[i] > 0) {
                v = i;
                flag = true;
                break;
            }
        }
        if (!flag) {
            break;
        }

        //6. Construir uma cadeia fechada H, a partir de v, percorrendo as arestas de G
        vector<int> temp;
        temp.push_back(v);

        while (true) {
            bool flag = false;
            for (int i = 0; i < n; i++) {
                if (aux[v][i] >= 0) {
                    flag = true;
                    temp.push_back(i);
                    aux[v][i] = -1;
                    v = i;
                    break;
                }
            }
            if (!flag) {
                break;
            }
        }
        //7. Remover de G as arestas de H
        for (int i = 0; i < temp.size() - 1; i++) {
            aux[temp[i]][temp[i + 1]] = 0;
            degrees[temp[i]]--;
            degrees[temp[i + 1]]++;
        }
        //8. C ← H ∪ C
        auto it = find(eulerianPath.begin(), eulerianPath.end(), v);
        eulerianPath.insert(it + 1, temp.begin(), temp.end());
       
        //9. H ← Ø
    }   
    //10. Fim_do_enquanto

    //11. Imprimir C
    for (int i = 0; i < eulerianPath.size(); i++) {
        cout << eulerianPath[i] + 1 << " ";
    };
}   

