#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
struct Point{int x,y; Point(){}; Point(int _x, int _y):x(_x),y(_y){}};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N,M; cin >> N >> M;
    
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int u,v; cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
    }

    queue<pair<int, int>> que;
    vector<bool> visited(N, false);
    que.push(make_pair(0,0));
    while(!que.empty()){
        auto[v, dist] = que.front();
        que.pop();

        if(visited[v] && v == 0){
            cout << dist << endl;
            return 0;
        }
        if(visited[v]){
            continue;
        }
        visited[v] = true;

        for(int i = 0; i < G[v].size(); i++){
            que.push(make_pair(G[v][i], dist+1));
        }
    }

    cout << -1 << endl;
    return 0;
}