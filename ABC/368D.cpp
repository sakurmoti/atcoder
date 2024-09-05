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
    int N,K; cin >> N >> K;
    vector<vector<int>> G(N);
    for(int i = 0; i < N-1; i++){
        int a,b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    set<int> target;
    for(int i = 0; i < K; i++){
        int v; cin >> v;
        v--;
        target.insert(v);
    }

    set<int> nodes;
    vector<bool> visited(N, false);
    auto dfs = [&](auto self, int now) -> bool {
        if(visited[now]) return false;
        visited[now] = true;

        // printf("now = %d\n", now);

        bool ret = false;
        if(target.contains(now)){
            target.erase(now);
            ret = true;
        }

        for(int i = 0; i < G[now].size(); i++){
            bool res = self(self, G[now][i]);
            ret = ret or res;
        }

        if(ret) nodes.insert(now);
        return ret;
    };

    dfs(dfs, *target.begin());

    // for(auto &_v : nodes) cout << _v << " "; cout << endl;

    cout << nodes.size() << endl;
    return 0;
}