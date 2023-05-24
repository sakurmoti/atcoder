#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<vector<long long>> C(N, vector<long long>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> C.at(i).at(j);
        }
    }

    /*条件を満たす数列A', B'が存在すると仮定する
    このとき、A'の最小値がmとするとA'からmを引き、B'にmを足した数列も条件を満たす
    つまりAの最小値が0になるようにしてもよい
    するとそれに対応するBが決まって芋づる式に決めることができる
    それが条件を満たすか確認すればよい*/

    /*Ai + Bj = C[i][j] ゆえにAk = C[k][j] - B[j]
    jを固定するとB[j]が定数になるので、Aiの最小値はC[i][j]の最小値に等しくなる
    j=0とすると Ai =0, C[i][0] = B[0]となる*/
    vector<long long> A(N),B(N);
    int cMin = 1e9;
    for(int i = 0; i < N; i++){
        if(cMin > C.at(i).at(0)){
            cMin = C.at(i).at(0);
        }
    }

    //B[0]が決まったのでA[i] + B[0] = C[i][0] からA[i]を求めにいく
    for(int i = 0; i < N; i++){
        A.at(i) = C.at(i).at(0) - cMin;
    }

    //A[i]が全て求められたのでB[j]を全て求めに行く。今回はA[0]を基準に決める
    for(int j = 0; j < N; j++){
        B.at(j) = C.at(0).at(j) - A.at(0);
    }

    //全てのC[i][j]と辻褄があうか確認
    //A，Bが正整数か確認も同時にする
    bool flag = true;
    for(int i = 0; i < N && flag; i++){
        if(A.at(i) < 0 || B.at(i) < 0){
            flag = false;
        
        }

        for(int j = 0; j < N && flag; j++){
            if(A.at(i) + B.at(j) != C.at(i).at(j)){
                flag = false;
            
            }
        }
    }

    if(flag){
        cout << "Yes" << endl;
        for(int i = 0; i < N; i++){
            cout << A.at(i) << (i == N-1 ? "\n" : " ");
        }
        for(int i = 0; i < N; i++){
            cout << B.at(i) << (i == N-1 ? "\n" : " ");
        }

    }else{
        cout << "No" << endl;

    }
    return 0;
}