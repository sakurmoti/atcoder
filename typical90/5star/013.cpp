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
    vector<vector<pair<int, int>>> G(N);
    for(int i = 0; i < M; i++){
        int u,v,c; cin >> u >> v >> c;
        u--; v--;
        G[u].push_back(make_pair(v, c));
        G[v].push_back(make_pair(u, c));
    }

    auto dijkstra = [&](int st) -> vector<int> {
        vector<int> ret(N, 0);
        vector<bool> decided(N, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
        pque.push(make_pair(0, st));

        while(!pque.empty()){
            auto [c, now] = pque.top();
            pque.pop();

            if(decided[now]) continue;
            decided[now] = true;
            ret[now] = c;

            for(int i = 0; i < G[now].size(); i++){
                auto[nex, cost] = G[now][i];
                pque.push(make_pair(c+cost, nex));
            }
        }

        return ret;
    };

    vector<int> from_st = dijkstra(0);
    vector<int> from_gl = dijkstra(N-1);
    for(auto &_v : from_st) cout << _v << " "; cout << endl;
    for(auto &_v : from_gl) cout << _v << " "; cout << endl;

    for(int i = 0; i < N; i++){
        cout << from_st[i] + from_gl[i] << endl;
    }
    return 0;
}