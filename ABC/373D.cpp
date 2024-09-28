#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
struct Point{int x, y;};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N,M; cin >> N >> M;
    vector<vector<tuple<ll, ll, ll>>> G(N);
    for(int i = 0; i < M; i++){
        int u,v,w; cin >> u >> v >> w;
        u--; v--;
        G[u].push_back(make_tuple(1, v, w));
        G[v].push_back(make_tuple(-1, u, w));
    }

    vector<ll> ans(N, 0);
    vector<bool> visited(N, false);
    vector<bool> decided(N, false);
    auto dfs = [&](auto self, int now) -> void {
        if(visited[now]) return;
        visited[now] = true;

        for(int i = 0; i < G[now].size(); i++){
            auto [rev, next, weight] = G[now][i];
            ans[next] = ans[now] + (rev * weight);
            self(self, next);
        }
        decided[now] = true;
    };

    for(int i = 0; i < N; i++){
        if(!decided[i]){
            ans[i] = 0;
            dfs(dfs, i);
        }
    }

    for(auto &_v : ans) cout << _v << " "; cout << endl;
    return 0;
}