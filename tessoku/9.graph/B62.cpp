#include <bits/stdc++.h>
using namespace std;

int N,M;
vector<vector<int>> G;
vector<bool> visited;
stack<int> route;
bool flag = false;
void dfs(int v){
    route.push(v);
    visited.at(v) = true;

    if(v == N){
        vector<int> ans;
        while(!route.empty()){
            int v = route.top();
            ans.push_back(v);
            route.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        for(auto v : ans) cout << v << " ";
    }

    for(auto next_v : G.at(v)){
        if(!visited.at(next_v)) dfs(next_v);
    }

    if(!route.empty())route.pop();

}

int main(){
    cin >> N >> M;

    G.resize(N+1);
    visited.assign(N+1, false);
    for(int i = 0; i < M; i++){
        int u,v;
        cin >> u >> v;

        G.at(u).push_back(v);
        G.at(v).push_back(u);
    }

    dfs(1);
    
    return 0;
}