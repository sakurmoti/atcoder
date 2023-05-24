#include <bits/stdc++.h>
using namespace std;

int N,M;
vector<vector<int>> Graph;
vector<int> dist;
queue<int> que;

void bfs(){
    while(!que.empty()){
        int v = que.front();
        que.pop();

        //頂点vとつながっている頂点を探索
        for(int next_v : Graph.at(v)){

            //行ったことある
            if(dist.at(next_v) != -1){
                continue;
            }

            dist.at(next_v) = dist.at(v) + 1;
            que.push(next_v);
        }
    }

}

int main(){
    cin >> N >> M;

    
    Graph.resize(N);
    dist.resize(N, -1);

    for(int i = 0; i < M; i++){
        int u,v;
        cin >> u >> v;

        //0-idxにする
        u--;
        v--;
        Graph.at(u).push_back(v);
        Graph.at(v).push_back(u);
    }

    dist.at(0) = 0;
    que.push(0);
    bfs();

    int ans = 0;
    for()

    cout << ans << endl;
    return 0;
}