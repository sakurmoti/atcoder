#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N,M;
ll ans = -1;
vector<vector<ll>> G;

void dfs(int now, ll cost, vector<bool> visited){
    ans = max(ans, cost);
    visited[now] = true;

    for(int i = 1; i <= N; i++){
        if(visited[i]) continue;
        dfs(i, cost+G[now][i], visited);
    }
}

int main(){
    cin >> N >> M;
    G.resize(N+1, vector<ll>(N+1, -1e10));

    for(int i = 0; i < M; i++){
        int A,B,C;
        cin >> A >> B >> C;
        G[A][B] = C;
        G[B][A] = C;
    }

    vector<bool> initialze(N+1, false);
    for(int i = 1; i <= N; i++){
        dfs(i, 0, initialze);
    }
    cout << ans << endl;
    return 0;
}