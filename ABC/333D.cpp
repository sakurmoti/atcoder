#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int N;
vector<bool> visited;
vector<vector<int>> G;

void dfs(int now, int &cnt){
    if(visited[now]) return;
    visited[now] = true;

    for(int i = 0; i < G[now].size(); i++){
        dfs(G[now][i], cnt);
    }

    cnt++;
}

int main(){
    cin >> N;
    visited.resize(N, false);
    G.resize(N);

    for(int i = 1; i <= N-1; i++){
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    // 頂点0から出る辺を1つにすることを考える
    // 最も消すのに時間がかかる辺以外を消せばいい
    int M = G[0].size();
    visited[0] = true;
    vector<int> edges;
    for(int i = 0; i < M; i++){
        int cnt = 0;
        dfs(G[0][i], cnt);
        edges.push_back(cnt);
    }

    sort(ALL(edges));

    int ans = 0;
    for(int i = 0; i < edges.size()-1; i++){
        ans += edges[i];
    }

    // 最後に頂点0自身を消すので+1
    cout << ans+1 << endl;
    return 0;
}