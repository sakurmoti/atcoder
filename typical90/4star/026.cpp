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
        int u,v; cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    // for(auto &_v : G){ for(auto &_vv : _v) cout << _vv << " "; cout << endl; }

    vector<bool> visited(N, false);
    vector<int> mark(N, -1);
    mark[0] = 0;
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int v = que.front();
        que.pop();

        if(visited[v]) continue;
        visited[v] = true;

        for(auto nx : G[v]){
            if(visited[nx]) continue;
            mark[nx] = (mark[v]+1)%2;
            que.push(nx);
        }
    }

    int cnt=0,k=0;
    for(auto &v : mark) if(v==1) cnt++;
    if(cnt > N/2){
        for(int i = 0; i < N; i++){
            if(mark[i] == 1 && k < N/2){
                cout << i+1 << " ";
                k++;
            }
        }
    }else{
        for(int i = 0; i < N; i++){
            if(mark[i] == 0 && k < N/2){
                cout << i+1 << " ";
                k++;
            }
        }
    }
    return 0;
}