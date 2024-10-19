#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

//Leitura da entrada do grafo e atualização da matriz
void lerMatriz(vector<vi>& matrix, int qnt){
    int x, y, cnt = 0;

    cout << "Informe as conexões existentes entre os vértices, uma por linha:" << endl;
    cout << "Siga o exemplo: \"4 5\" indica que os vértices 4 e 5 são conectados" << endl;

    while(qnt > 0){
        cin >> x >> y;

        matrix[cnt][--x] = 1;
        matrix[cnt][--y] = 1;

        cnt++;
        qnt--;
    }

}

//Impressão da matriz de incidênncia resultante
void imprimirMatriz(vector<vi> matrix){
    cout << "Matriz de Incidência resultante: " << endl; 
    cout << "---------------------------------" << endl;
    cout << " ";
    
    for(auto i{0u}; i<matrix[0].size(); ++i) cout << " "<< i+1;
    cout << endl;

    for(auto i{0u}; i<matrix.size(); ++i){
        cout <<i+1;
        for(auto j{0u}; j<matrix[i].size(); ++j){
            cout << " " << matrix[i][j];
        }

        cout << endl;
    }
    cout << "---------------------------------" << endl;
}

int main(){

    int x = 0, y = 0;

    cout << "Informe a quantidade de conexões que o grafo possui: " << endl;
    cin >> x;

    cout << "Informe a quantidade de vértices da matriz: " << endl;
    cin >> y;

    //Inicialização da matriz de incidência do grafo
    vector<vi> matrix (x, vi(y, 0));

    lerMatriz(matrix, x);

    imprimirMatriz(matrix);

    return 0;
}