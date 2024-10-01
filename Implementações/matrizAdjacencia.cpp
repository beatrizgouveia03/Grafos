#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

int main(){
    vector<vi> matrix (10, vi(10, 0));

    int x, y;

    while(cin >> x >> y){
        matrix[--x][--y] = 1;
        matrix[y][x] = 1;
    }

    cout << " ";
    for(auto i{0u}; i<10; ++i) cout << " "<< i+1;
    cout << endl;

    for(auto i{0u}; i<10; ++i){
        cout <<i+1;
        for(auto j{0u}; j<10; ++j){
            cout << " " << matrix[i][j];
        }

        cout << endl;
    }


    return 0;
}