#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N,M,T;
    cin >> N >> M >> T;
    vector<ll> A(N-1);
    for(auto &v : A) cin >> v;

    vector<ll> bonus(N, 0);
    for(int i = 0; i < M; i++){
        int x,y;
        cin >> x >> y;
        x--;
        bonus[x] = y;
    }

    for(int i = 0; i < N-1; i++){
        T -= A[i];
        // cout << T << endl;
        if(T <= 0){
            cout << "No" << endl;
            return 0;
        }

        T += bonus[i+1];
    }

    cout << "Yes" << endl;
    return 0;
}