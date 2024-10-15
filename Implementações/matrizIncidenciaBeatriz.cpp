#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

int main(){
    vector<vi> matrix (10, vi(10, 0));

    int x, y, cnt = 0;

    while(cin >> x >> y){
        matrix[cnt][--x] = 1;
        matrix[cnt][--y] = 1;
        cnt++;
    }

    cout << "  ";
    for(auto i{0u}; i<10; ++i) cout << " "<< i+1;
    cout << endl;

    for(auto i{0u}; i<cnt; ++i){
        cout << "u" <<i+1;
        for(auto j{0u}; j<10; ++j){
            cout << " " << matrix[i][j];
        }

        cout << endl;
    }


    return 0;
}