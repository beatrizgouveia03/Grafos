#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

//Leitura da entrada do grafo e atualização da matriz
bool lerMatriz(vector<vi>& matrizAdj){
    int vertices, conexoes, x, y;
    
    cout << "Leitura de vértices e conexões..." << endl;

    //Quantidade de vértices e conexoes da matriz
    cin >> vertices >> conexoes;

    cout << "Leitura concluída: Vértices - " << vertices << ", Conexões - " << conexoes << endl;

    matrizAdj = vector<vi>(vertices, vi(vertices, 0));

    cout << "Lendo conexões..." << endl;

    while(conexoes > 0){
        cin >> x >> y;

        cout << "Conexão lida: " << x << " " << y << endl;

        if(x<1||x>vertices||y<1||y>vertices){
            cout << "Erro: Vértice fora do intervalo." << endl;
            return false;
        }

        matrizAdj[--x][--y] = 1;
        matrizAdj[y][x] = 1;

        cout << "Conexão lida com sucesso." << endl;

        --conexoes;
    }

    return true;
}

//Impressão da matriz de adjacência resultante
void imprimirMatriz(vector<vi> matrizAdj){
    cout << endl;
    cout << "Matriz de Adjacência resultante: " << endl; 
    cout << "---------------------------------" << endl;
    cout << " ";

    for(auto i{0u}; i<matrizAdj.size(); ++i) cout << " " << i+1;
    cout << endl;

    for(auto i{0u}; i<matrizAdj.size(); ++i){
        cout <<i+1;
        for(auto j{0u}; j<matrizAdj.size(); ++j){
            cout << " " << matrizAdj[i][j];
        }

        cout << endl;
    }
    cout << "---------------------------------" << endl;
}

int main(){
    //Inicialização da matriz de adjacência do grafo
    vector<vi> matrizAdj;
    
    if(lerMatriz(matrizAdj)) imprimirMatriz(matrizAdj);

    return 0;
}