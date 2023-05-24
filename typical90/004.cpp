#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,W;
    cin >> H >> W;

    vector<vector<int>> A(H, vector<int>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> A.at(i).at(j);
        }
    }

    vector<int> row_sum(H); //横方向(行)の総和
    vector<int> column_sum(W); //縦方向(列)の総和
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            row_sum.at(i) += A.at(i).at(j);
            column_sum.at(j) += A.at(i).at(j);
        }
    }
    
    vector<vector<int>> B(H,vector<int>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            B.at(i).at(j) = row_sum.at(i) + column_sum.at(j) -A.at(i).at(j);
            cout << B.at(i).at(j);

            if(j != W-1) cout << " ";
            else cout << endl;
        }
    }

    return 0;
}