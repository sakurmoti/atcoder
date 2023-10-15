#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    vector<ll> D(N+1);
    for(int i = 1; i <= N; i++){
        cin >> D[i];
    }
    D[0] = D[N];

    vector<ll> M(N+1, 0);
    for(int i = 1; i <= N; i++){
        M[i] += 
        cout << M[i] << " \n"[i==N];
    }
    return 0;
}