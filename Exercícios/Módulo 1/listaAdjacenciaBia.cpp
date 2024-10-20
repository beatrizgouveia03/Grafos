#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

//Leitura da entrada do grafo e atualização da lista
bool lerGrafo(map<int, vi>& listaAdj){
    int vertices, conexoes, x, y;

    cout << "Leitura de vértices e conexões..." << endl;
    
    //Quantidade de vértices e conexoes da matriz
    cin >> vertices >> conexoes;

    cout << "Leitura concluída: Vértices - " << vertices << ", Conexões - " << conexoes << endl;

    for(auto i{1u}; i<=vertices; ++i) listaAdj[i];

    cout << "Lendo conexões..." << endl;


    while(conexoes > 0){
        cin >> x >> y;

        cout << "Conexão lida: " << x << " " << y << endl;

        if(x<1||x>vertices||y<1||y>vertices){
            cout << "Erro: Vértice fora do intervalo." << endl;
            return false;
        }

        listaAdj[x].push_back(y);
        listaAdj[y].push_back(x);

        cout << "Conexão lida com sucesso." << endl;

        conexoes--;
    }
    
    return true;
}

//Impressão da lista de adjacência resultante
void imprimirGrafo(map<int, vi> listaAdj){
    cout << endl;
    cout << "Lista de Adjacência resultante: " << endl; 
    cout << "---------------------------------" << endl;

    for(auto i{1u}; i<=listaAdj.size(); ++i){
        cout << i << " ->";
        if(listaAdj[i].size() == 0) cout << " Sem adjacentes";
        else {
            for(auto j{0u}; j < listaAdj[i].size(); ++j){
                cout << " " <<  listaAdj[i][j];
            }
        }
        cout << endl;
    }
    cout << "---------------------------------" << endl;
}

int main(){
    //Inicialização da lista de adjacência do grafo
    map<int, vi> listaAdjacencia;
    
    if(lerGrafo(listaAdjacencia)) imprimirGrafo(listaAdjacencia);

    return 0;
}