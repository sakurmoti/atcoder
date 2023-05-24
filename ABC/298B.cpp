#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int N;
    cin >> N;

    vector<vector<int>> A(N,vector<int>(N)), B(N,vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> A[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> B[i][j];
        }
    }

    vector<vector<int>> buf(N, vector<int>(N));
    for(int cnt = 0; cnt < 4; cnt++){
        for (int i = 0; i < N; i++) {
            for (int j = N - 1; j >= 0; j--) {
                buf[i][N - j - 1] = A[j][i];
            }
        }

        bool flag = true;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(A[i][j] == 1){
                    if(B[i][j] != 1) flag = false;
                }
            }
        }

        if(flag){
            cout << "Yes" << endl;
            return 0;
        }
        
        /*cout << endl;
        for(auto x : A){
            for(auto y : x) cout << y << " ";
            cout << endl;
        }*/

        A = buf;
    }
    cout << "No" << endl;
    return 0;
}