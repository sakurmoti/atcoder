#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string S; cin >> S;
    int N = S.size()+1;
    vector<ll> A(N, 0);

    //A[0] S[0] A[1] S[1] A[2]
    for(int i = 0; i < N; i++){
        //右に見ていく
        if(S[i] == '<'){
            A[i+1] = A[i]+1;
        }
    }

    for(int i = N-1; i >= 0; i--){
        //左に見ていく
        if(S[i] == '>'){
            A[i] = max(A[i], A[i+1]+1);
        }
    }

    ll sum = 0;
    for(auto &v : A){
        // cout << v << ' ';
        sum += v;
    }
    cout << sum << endl;
    return 0;
}