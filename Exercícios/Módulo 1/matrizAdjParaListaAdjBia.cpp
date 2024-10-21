#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

//Leitura da entrada do grafo e atualização da lista
bool lerMatriz(map<int, vi>& listaAdj){
    int x, vertices;

    cout << "Leitura de vértices..." << endl;
    
    //Quantidade de vértices da matriz
    cin >> vertices;

    cout << "Leitura concluída: Vértices - " << vertices << endl;

    for(auto i{1u}; i<=vertices; ++i) listaAdj[i];

    cout << "Lendo matriz..." << endl;

    for(auto i{0u}; i<vertices; ++i){
        for (auto j(0u); j<vertices;++j){
            cin >> x;

            cout << x << " ";

            if(x!=0 && x != 1){
                cout << "Erro: Valor inválido." << endl;
                return false;
            }


            if(x && j >= i){
                if(i == j) {
                    listaAdj[i+1].push_back(j+1);
                } else {                
                    listaAdj[i+1].push_back(j+1);
                    listaAdj[j+1].push_back(i+1);
                }
            }
        }
        cout << endl;
    }

    return true;
}

//Impressão da lista de adjacência resultante
void imprimirListaAdj(map<int, vi> listaAdj){
    cout << endl;
    cout << "Lista de Adjacência resultante: " << endl; 
    cout << "---------------------------------" << endl;

    for(auto i{1u}; i<=listaAdj.size(); ++i){
        cout << i << " ->";
        for(auto j{listaAdj[i].begin()}; j != listaAdj[i].end(); ++j){
            cout << " " <<  *j;
        }
        cout << endl;
    }
    cout << "---------------------------------" << endl;
}

int main(){
    //Inicialização da lista de adjacência do grafo
    map<int, vi> listaAdj;


    if(lerMatriz(listaAdj)) imprimirListaAdj(listaAdj);

    return 0;
}