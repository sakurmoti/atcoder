#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,K; cin >> N >> K;
    vector<int> A(K);
    for(auto &_v : A) cin >> _v;

    // a,b,b,cのとき、(b-a) + (c-b) = c-a より同じ色はペアにしてよい
    // Aの中で差の総和を最小化

    vector<int> pre(K+1,0), suf(K+1, 0);
    for(int i = 1; i <= K; i++){
        if(i%2 == 0) pre[i] = pre[i-1] + abs(A[i-1] - A[i-2]);
        else pre[i] = pre[i-1];
    }

    for(int i = K-1; i >= 0; i--){
        if( (K-i)%2 == 0) suf[i] = suf[i+1] + abs(A[i+1] -A[i]);
        else suf[i] = suf[i+1];
    }

    // for(int _i = 0; _i < pre.size(); _i++){
    //     cout << pre[_i] << " \n"[_i == pre.size()-1];
    // }

    // for(int _i = 0; _i < suf.size(); _i++){
    //     cout << suf[_i] << " \n"[_i == suf.size()-1];
    // }

    int ans = 1e9;
    for(int i = 0; i <= K; i+=2){
        ans = min(ans, pre[i] + suf[i]);
    }

    cout << ans << endl;
    return 0;
}