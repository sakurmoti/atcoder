#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,M; cin >> N >> M;
    vector<int> X(M);
    for(auto &v : X){
        cin >> v;
    }

    // 消す橋を全探索することを考える
    // 橋N と橋0 は同じ意味と定義
    // ans[i] := 橋iを壊した時のツアーの最短
    // imos[i] := ans[i] - ans[i-1]
    vector<ll> imos(N+1, 0);

    // 橋Nを破壊した場合を基準に考える
    for(int i = 0; i < M-1; i++){
        int l = min(X[i], X[i+1]);
        int r = max(X[i], X[i+1]);

        // 橋Nを破壊した場合、l, l+1, l+2, ... , rと行くしかない
        imos[0] += (r-l);

        // 橋l から橋r-1を破壊した場合、逆方向に行くしかない
        imos[l] += (l + (N-r)) - (r-l);
        imos[r] -= (l + (N-r)) - (r-l); 
    }

    ll ans = 1e18;
    for(int i = 1; i <= N; i++){
        imos[i] += imos[i-1];
        ans = min(ans, imos[i]);
    }
    cout << ans << endl;
    return 0;
}