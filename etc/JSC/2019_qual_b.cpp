#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;

int main(){
    ll N,K;
    cin >> N >> K;

    vector<int> A(N);
    for(auto &v : A) cin >> v;

    //AがK個連なる列をB1,B2...Bkとする
    //このとき、転倒数はBの内部で発生するものと、Bi,Bj間で発生するもののみ
    //内部で発生するものはAの内部で発生する個数をK倍すれば求まる
    //2つのBの間で発生するのは愚直に個数を求めたのち、K個から2つ組合せ数を計算して積をとる

    //内部
    mint inter = 0;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            if(A[i] > A[j]){
                inter++;
            }
        }
    }

    //外部
    mint outer = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(A[i] > A[j]){
                outer++;
            }
        }
    }

    mint Combination = K*(K-1)/2; //kC2

    cout << (inter*K + outer*Combination).val() << endl;
    return 0;
}