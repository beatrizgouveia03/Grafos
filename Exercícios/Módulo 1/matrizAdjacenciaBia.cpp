#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

//Leitura da entrada do grafo e atualização da matriz
void lerMatriz(vector<vi>& matrix){
    int qnt, x, y;
    cout << "Informe a quantidade de conexões que o grafo possui: " << endl;

    cin >> qnt;

    cout << "Informe as conexões existentes entre os vértices, uma por linha:" << endl;
    cout << "Siga o exemplo: \"4 5\" indica que os vértices 4 e 5 são conectados" << endl;

    while(qnt > 0){
        cin >> x >> y;

        matrix[--x][--y] = 1;
        matrix[y][x] = 1;

         qnt--;
    }

}

//Impressão da matriz de adjacência resultante
void imprimirMatriz(vector<vi> matrix){
    cout << "Matriz de Adjacência resultante: " << endl; 
    cout << "---------------------------------" << endl;
    cout << " ";

    for(auto i{0u}; i<matrix.size(); ++i) cout << " "<< i+1;
    cout << endl;

    for(auto i{0u}; i<matrix.size(); ++i){
        cout <<i+1;
        for(auto j{0u}; j<matrix.size(); ++j){
            cout << " " << matrix[i][j];
        }

        cout << endl;
    }
    cout << "---------------------------------" << endl;
}

int main(){
    int x;
    
    cout << "Informe a quantidade de vértices da matriz: " << endl;
    cin >> x;

    //Inicialização da matriz de adjacência do grafo
    vector<vi> matrix (x, vi(x, 0));


    lerMatriz(matrix);

    imprimirMatriz(matrix);

    return 0;
}