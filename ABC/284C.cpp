#include <bits/stdc++.h>
using namespace std;

int N,M;
vector<vector<int>> Graph;
vector<bool> isCome;

void dfs(int start){
    if(isCome.at(start)) return;
    isCome.at(start) = true;

    for(int i = 0; i < Graph.at(start).size(); i++){
        dfs(Graph.at(start).at(i));
    }
    
}

int main(){
    cin >> N >> M;
    Graph.resize(N);
    isCome.resize(N, false);

    int u,v;
    for(int i = 0; i < M; i++){
        cin >> u >> v;

        Graph.at(u-1).push_back(v-1);
        Graph.at(v-1).push_back(u-1);
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        if(isCome.at(i)){
            //この部分グラフは探索済み
            continue;

        }else{
            //まだ探索していない部分グラフ
            ans++;
            dfs(i);

        }
    }

    cout << ans << endl;
    return 0;
}