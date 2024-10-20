#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

//Leitura da entrada do grafo e atualização da lista
void lerGrafo(map<int, vi>& graph){
    int vertices, conexoes, x, y;
    
    //Quantidade de vértices e conexoes da matriz
    cin >> vertices >> conexoes;

    for(auto i{1u}; i<=vertices; ++i) graph[i];


    while(conexoes > 0){
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);

        conexoes--;
    }

}

//Impressão da lista de adjacência resultante
void imprimirGrafo(map<int, vi> graph){
    cout << "Lista de Adjacência resultante: " << endl; 
    cout << "---------------------------------" << endl;

    for(auto i{1u}; i<=graph.size(); ++i){
        cout << i << " ->";
        if(graph[i].size() == 0) cout << " Sem adjacentes";
        else {
            for(auto j{0u}; j < graph[i].size(); ++j){
                cout << " " <<  graph[i][j];
            }
        }
        cout << endl;
    }
    cout << "---------------------------------" << endl;
}

int main(){
    //Inicialização da lista de adjacência do grafo
    map<int, vi> listaAdjacencia;
    
    lerGrafo(listaAdjacencia);

    imprimirGrafo(listaAdjacencia);

    return 0;
}