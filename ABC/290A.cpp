#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int N,M;
    cin >> N >> M;

    vector<int> A(N),B(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];

    long long sum=0;
    for(int i = 0; i < M; i++){
        B[i]--;
        sum += A[B[i]];
    }
    cout << sum << endl;
    return 0;
}