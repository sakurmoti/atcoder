#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N,M; cin >> N >> M;
    vector<ll> A(N);
    for(auto &_v : A) cin >> _v;

    vector<vector<pair<ll, int>>> G(N);
    for(int i = 0; i < M; i++){
        ll u,v,b; cin >> u >> v >> b;
        u--; v--;

        // 始点と辺をまとめて重みとする
        G[u].push_back(make_pair(b+A[u], v));
        G[v].push_back(make_pair(b+A[v], u));
    }

    vector<bool> decided(N, false);
    vector<ll> dist(N, 1e18);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pque;
    pque.push(make_pair(0,0));

    while(!pque.empty()){
        auto[c, now] = pque.top();
        pque.pop();

        // printf("%d %d\n", c, now);
        if(decided[now]) continue;
        decided[now] = true;

        for(int i = 0; i < G[now].size(); i++){
            auto[cost, next] = G[now][i];

            if(dist[next] > c + cost){
                dist[next] = c + cost;
                pque.push(make_pair(c+cost, next));
            }
        }
    }

    for(int i = 1; i < N; i++){
        cout << dist[i]+A[i] << " ";
    }
    return 0;
}