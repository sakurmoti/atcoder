#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

#include <atcoder/all>
using namespace atcoder;

int main(){
    int N,M; cin >> N >> M;

    vector<pair<ll, vector<int>>> edges;
    for(int i = 0; i < M; i++){
        ll K,C;
        cin >> K >> C;

        vector<int> A(K);
        for(int j = 0; j < K; j++){
            cin >> A[j];
        }

        edges.push_back(make_pair(C,A));
    }

    sort(ALL(edges));

    vector<bool> used(N+1, false);
    dsu d(N+1);
    ll ans = 0;

    // コストの低い順に取る= クラスカル法
    for(int i = 0; i < M; i++){
        auto [cost, edge] = edges[i];

        // 頂点edge[0]を固定して考える
        int u = edge[0];
        for(int j = 1; j < edge.size(); j++){
            int v = edge[j];

            if(d.same(u,v)) continue;
            else{
                d.merge(u,v);
                ans += cost;
            }
        }
    }

    if(d.groups().size() != 2) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}