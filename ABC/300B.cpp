#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int H,W;
bool solve(int s, int t, vector<vector<char>> A, vector<vector<char>> B){
    for(int q = 0; q < s; q++){
        
        vector<char> buf = A[0];
        for(int i = 0; i < H-1; i++){
            A[i] = A[i+1];
        }
        A[H-1] = buf;
    }

    for(int q = 0; q < t; q++){

        for(int i = 0; i < H; i++){
            char c = A[i][0];
            for(int j = 0; j < W-1; j++){
                A[i][j] = A[i][j+1];
            }
            A[i][W-1] = c;
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(A[i][j] != B[i][j]) return false;
        }
    }
    return true;
}

int main(){
    cin >> H >> W;

    vector<vector<char>> A(H, vector<char>(W)),B(H, vector<char>(W));
    vector<int> countAH(W,0), countAW(H,0);
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> A[i][j];
        }
    }
    
    vector<int> countBH(W,0), countBW(H,0);
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> B[i][j];
        }
    }

    for(int i = 0; i <= H; i++){
        for(int j = 0; j <= W; j++){
            bool flag = solve(i,j,A,B);

            if(flag){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}