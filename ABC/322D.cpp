#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    vector<vector<vector<char>>> P(3, vector<vector<char>>(4, vector<char>(4)));
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                cin >> P[i][j][k];
            }
        }
    }

    vector<vector<char>> tile(30, vector<char>(30, '.'));
    

    return 0;
}