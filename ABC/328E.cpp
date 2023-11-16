#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

#include <atcoder/all>
using namespace atcoder;

ll N,M,K;
vector<vector<ll>> G;

int main(){
    cin >> N >> M >> K;
    G.resize(N+1, vector<ll>(N+1, 1e18));
    vector<pair<int, int>> sides(M);
    for(int i = 0; i < M; i++){
        ll u,v,w; cin >> u >> v >> w;
        sides[i].push_back(make_pair(u,v));
        G[u][v] = w;
        G[v][u] = w;
    }

    vector<int> comb(M);
    return 0;
}