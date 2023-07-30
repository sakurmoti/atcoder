#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    vector<int> X(N);
    for(auto &v : X) cin >> v;

    ll ans = 1e10;
    for(int P = 0; P <= 100; P++){
        ll health = 0;
        for(int i = 0; i < N; i++){
            health += (X[i]-P)*(X[i]-P);
        }

        ans = min(ans, health);
    }

    cout << ans << endl;
   return 0;
}