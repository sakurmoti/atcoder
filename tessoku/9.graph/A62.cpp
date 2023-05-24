#include <bits/stdc++.h>
using namespace std;

int N,M;
vector<vector<int>> G;
vector<bool> visited;

void dfs(int u){
    if(visited.at(u)) return;
    visited.at(u) = true;

    for(auto v : G.at(u)) dfs(v);
}

int main(){
    cin >> N >> M;
    G.resize(N+1);
    visited.resize(N+1, false);

    for(int i = 0; i < M; i++){
        int u,v;
        cin >> u >> v;

        G.at(u).push_back(v);
        G.at(v).push_back(u);
    }

    dfs(1); //頂点1から探索

    //連結ならすべて探索済みのはず
    for(int i = 1; i <= N; i++){
        if(!visited[i]){
            cout << "The graph is not connected." << endl;
            return 0;
        }
    }
    cout <<  "The graph is connected." << endl;
    return 0;
}