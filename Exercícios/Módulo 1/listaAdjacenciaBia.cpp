#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

//Leitura da entrada do grafo e atualização da lista
void lerGrafo(map<int, vi>& graph){
    int qnt , x, y;
    cout << "Informe a quantidade de conexões que o grafo possui: " << endl;

    cin >> qnt;

    cout << "Informe as conexões existentes entre os vértices, uma por linha:" << endl;
    cout << "Siga o exemplo: \"4 5\" indica que os vértices 4 e 5 são conectados" << endl;

    while(qnt > 0){
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);

        qnt--;
    }

}

//Impressão da lista de adjacência resultante
void imprimirGrafo(map<int, vi> graph, int x){
    cout << "Lista de Adjacência resultante: " << endl; 
    cout << "---------------------------------" << endl;

    for(auto i{1u}; i<=x; ++i){
        cout << i << " ->";
        for(auto j{0u}; j < graph[i].size(); ++j){
            cout << " " <<  graph[i][j];
        }
        cout << endl;
    }
    cout << "---------------------------------" << endl;
}

int main(){
    int x;
    
    cout << "Informe a quantidade de vértices da matriz: " << endl;
    cin >> x;

    //Inicialização da lista de adjacência do grafo
    map<int, vi> graph;


    lerGrafo(graph);

    imprimirGrafo(graph, x);

    return 0;
}