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
    vector<pair<int, int>> edges(M);
    for(int i = 0; i < M; i++){
        ll u,v,w; cin >> u >> v >> w;
        u--;
        v--;
        edges[i] = (make_pair(u,v));
        G[u][v] = w;
        G[v][u] = w;
    }

    // M個の辺からN-1個の辺を選ぶ
    vector<bool> comb(M, 0);
    for(int i = 0; i < N-1; i++){
        comb[i] = 1;
    }
    sort(ALL(comb));

    ll ans = K;
    do
    {
        dsu d(N);
        ll cost = 0;
        bool SpanningTree = true;

        for(int i = 0; i < M; i++){
            if(comb[i]){
                int a = edges[i].first;
                int b = edges[i].second;

                if(d.same(a,b)) SpanningTree = false;
                d.merge(a, b);
                cost += (G[a][b]%K);
            }
        }

        if(SpanningTree){
            ans = min(ans, cost%K);
        }


    } while (next_permutation(ALL(comb)));
    
    cout << ans << endl;
    return 0;
}