#include <bits/stdc++.h>
using namespace std;

int N,M;
bool flag = true;
vector<vector<int>> G;
vector<bool> visited;

void dfs(int v, int come){
    if(visited.at(v)){
        //cout << "v, come : " << v << " " << come << endl;
        flag = false;
        return;
    }

    visited.at(v) = true;
    for(int i = 0; i < G.at(v).size(); i++){
        int next = G.at(v).at(i);

        if(next == come) continue; //来たところには戻らない
        else dfs(next, v);
    }
    
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

    //直線か確かめればよい
    dfs(1, -1);

    for(int i = 1; i <= N; i++){
        if(visited.at(i)){
            continue;
        
        }else{
            flag = false;
        }
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}