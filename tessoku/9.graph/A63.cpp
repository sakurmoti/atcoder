#include <bits/stdc++.h>
using namespace std;

int N,M;
vector<vector<int>> Graph;
vector<int> ans;
int main(){
    cin >> N >> M;
    
    Graph.resize(N+1);
    ans.assign(N+1, 1e9);
    for(int i = 0; i < M; i++){
        int u,v;
        cin >> u >> v;

        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    queue<int> que;
    que.push(1); //頂点1をpush
    ans[1] = 0;
    while(!que.empty()){
        int v = que.front();
        que.pop();

        for(auto u : Graph[v]){
            if(ans[v]+1 <= ans[u]){
                que.push(u);
                ans[u] = ans[v]+1;
            }
        }

    }

    for(int i = 1; i <= N; i++){
        if(1e7 < ans[i]) cout << -1 << endl;
        else cout << ans[i] << endl;
    }
    return 0;
}