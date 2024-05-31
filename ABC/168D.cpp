#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
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
        G[v].push_back(u);
    }

    // for(auto &_v : G){ for(auto &_vv : _v) cout << _vv << " "; cout << endl; }

    vector<int> ans(N, -1);
    vector<bool> visited(N, false);
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int v = que.front();
        que.pop();

        // printf("v = %d\n",v);
        if(visited[v]) continue;
        visited[v] = true;

        for(auto next : G[v]){
            // printf("nx = %d\n",next);
            if(ans[next] >= 0) continue;

            ans[next] = v;
            que.push(next);
        }
        // printf("\n");
    }

    for(int i = 0; i < N; i++){
        if(!visited[i]){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    for(int i = 1; i < N; i++){
        cout << ans[i]+1 << endl;
    }
    return 0;
}