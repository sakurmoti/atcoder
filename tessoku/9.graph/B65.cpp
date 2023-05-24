#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &Graph ,vector<int> &ans ,int st, int prev){
    for(auto v : Graph[st]){
        if(v == prev) continue;
        dfs(Graph, ans, v, st);
    }
    
    if(prev != -1) ans[prev] = max(ans[prev], ans[st]+1);
}

int main(){
    int N,T;
    cin >> N >> T;

    vector<vector<int>> Graph(N+1);
    vector<int> ans(N+1, 0);
    for(int i = 0; i < N-1; i++){
        int a,b;
        cin >> a >> b;

        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    dfs(Graph, ans, T, -1);

    for(int i = 1; i <= N; i++) cout << ans[i] << " ";
    return 0;
}