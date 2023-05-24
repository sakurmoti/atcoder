#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,W;
    cin >> H >> W;

    vector<vector<int>> X(H+1, vector<int>(W+1, 0));
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            cin >> X.at(i).at(j);
        }
    }

    //まずは行に対して累積和
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            X.at(i).at(j) += X.at(i).at(j-1);
        }
    }

    //次に列に対して累積和を行うとXの二次元累積和が求まる
    //これによりX[i][j]には(0,0)から(i,j)が作る長方形の和になる
    for(int j = 1; j <= W; j++){
        for(int i = 1; i <= H; i++){
            X.at(i).at(j) += X.at(i-1).at(j);
        }
    }

    /*for(auto v : X){
        for(auto u : v){
            cout << u << " ";
        }
        cout << endl;
    }*/

    int Q;
    cin >> Q;
    
    int A,B,C,D;
    for(int i = 0; i < Q; i++){
        cin >> A >> B >> C >> D;
        A--;
        B--;

        //X[D][C]からX[B][C]とX[D][A]を引くとX[B][A]を二重に引くので足す
        cout << X.at(C).at(D) - X.at(C).at(B) - X.at(A).at(D) + X.at(A).at(B) << endl;
    }
    return 0;
}