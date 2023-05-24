#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int N;
    cin >> N;
    vector<long long> A(N);
    for(auto &v : A) cin >> v;

    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    
    /*今、Aは降順に並んでいる
    このとき、降順に輪にうまく入れていくと最大で
    A0+A1+A1+A2+A2...になる
    */
    long long ans = 0;
    for(int i = 1; i < N; i++){
        ans += A[i/2];
    }

    cout << ans << endl;
    return 0;
}