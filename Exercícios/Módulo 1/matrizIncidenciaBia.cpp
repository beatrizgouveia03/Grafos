#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

//Leitura da entrada do grafo e atualização da matriz
bool lerMatriz(vector<vi>& matrizInc){
    int vertices, conexoes, x, y;
    
    cout << "Leitura de vértices e conexões..." << endl;

    //Quantidade de vértices e conexoes da matriz
    cin >> vertices >> conexoes;

    cout << "Leitura concluída: Vértices - " << vertices << ", Conexões - " << conexoes << endl;

    matrizInc = vector<vi>(conexoes, vi(vertices, 0));

    cout << "Lendo conexões..." << endl;

    int cnt = 0;

    while(conexoes > 0){
        cin >> x >> y;

        cout << "Conexão lida: " << x << " " << y << endl;

        if(x<1||x>vertices||y<1||y>vertices){
            cout << "Erro: Vértice fora do intervalo." << endl;
            return false;
        }

        matrizInc[cnt][--x] = 1;
        matrizInc[cnt][--y] = 1;

        cnt++; conexoes--;
    }

    return true;
}

//Impressão da matriz de incidênncia resultante
void imprimirMatriz(vector<vi> matrizInc){
    cout << endl;
    cout << "Matriz de Incidência resultante: " << endl; 
    cout << "---------------------------------" << endl;
    cout << " ";
    
    for(auto i{0u}; i<matrizInc[0].size(); ++i) cout << " "<< i+1;
    cout << endl;

    for(auto i{0u}; i<matrizInc.size(); ++i){
        cout <<i+1;
        for(auto j{0u}; j<matrizInc[i].size(); ++j){
            cout << " " << matrizInc[i][j];
        }

        cout << endl;
    }
    cout << "---------------------------------" << endl;
}

int main(){

    //Inicialização da matriz de incidência do grafo
    vector<vi> matrizInc;

    if(lerMatriz(matrizInc)) imprimirMatriz(matrizInc);

    return 0;
}