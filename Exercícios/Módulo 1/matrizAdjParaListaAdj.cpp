#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

//Leitura da entrada do grafo e atualização da lista
void lerMatriz(map<int, set<int>>& graph, int x){
    int entry;

     cout << "Informe a matriz de adjancência separando os números com espaço (Ex.: 0 1 0)" << endl;
    
    for(auto i{0u}; i<x; ++i){
        for (auto j(0u); j<x;++j){
            cin >> entry;
            if(entry && j >= i){
                graph[i+1].insert(j+1);
                graph[j+1].insert(i+1);
            }
        }
    }
}

//Impressão da lista de adjacência resultante
void imprimirGrafo(map<int, set<int>> graph, int x){
    cout << "Lista de Adjacência resultante: " << endl; 
    cout << "---------------------------------" << endl;

    for(auto i{1u}; i<=x; ++i){
        cout << i << " ->";
        for(auto j{graph[i].begin()}; j != graph[i].end(); ++j){
            cout << " " <<  *j;
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
    map<int, set<int>> graph;


    lerMatriz(graph, x);

    imprimirGrafo(graph, x);

    return 0;
}