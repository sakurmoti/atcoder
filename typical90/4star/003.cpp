#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N; cin >> N;
    vector<vector<int>> G(N);
    for(int i = 0; i < N-1; i++){
        int a,b; cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 適当な頂点aから最も遠い点uを探し、uから遠い点vを求めれば木の直径が求まる
    auto bfs = [&](int u){
        int last,dist;
        vector<bool> visited(N, false);
        queue<pair<int, int>> que;
        que.push({u,0});
        while(!que.empty()){
            auto [v,d] = que.front(); que.pop();
            if(visited[v]) continue;
            visited[v] = true;

            for(auto next : G[v]){
                que.push({next, d+1});
            }

            last = v;
            dist = d;
        }

        return make_pair(last, dist);
    };

    auto [u,ud] = bfs(0);
    auto [v,vd] = bfs(u);
    // printf("u=%d, ud=%d\nv=%d,vd=%d\n",u,ud,v,vd);
    cout << vd+1 << endl;
    return 0;
}