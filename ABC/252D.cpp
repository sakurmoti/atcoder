#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    //条件を満たす組(i,j,k)と、(Ai,Aj,Ak)が昇順になるように入れ替えた組(s,t,u)は1対1に対応する
    //故にソートしてもよい
    sort(A.begin(), A.end());

    //B[i] := i以下のAの個数
    int M = *max_element(A.begin(), A.end());
    vector<int> B(M+1, 0);
    map<int, int> buf;
    for(int i = 0; i < N; i++) buf[A[i]]++;
    for(int i = 1; i <= M; i++){
        B[i] += (B[i-1] + buf[i]);
        // printf("B[%d] = %d\n", i,B[i]);
    }
    //このとき、真ん中のjに対して全探索することを考える
    ll ans = 0;
    for(int j = 1; j < N-1; j++){
        int a = A[j];
        //iはA[j]未満の個数
        ll I = B[a-1];

        //kはA[j]より大きい数の個数
        ll K = B[M] - B[a];

        //i,kは独立
        ans += I*K;
    }
    cout << ans << endl;
    return 0;
}