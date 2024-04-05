#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    ll N; cin >> N;

    vector<ll> f(N+1, 0);

    ll ans = 0;
    for(int k = 0; k <= N; k++){
        ans += k * f[k];
    }
    return 0;
}