#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    vector<vector<pair<int,int>>> Graph(N+1);
    for(int i = 0; i < M; i++){
        int u,v,weight;
        cin >> u >> v >> weight;

        Graph[u].push_back(make_pair(weight, v));
        Graph[v].push_back(make_pair(weight, u));
    }

    //ダイクストラ法を使うためのデータ構造を用意
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> que;
    vector<bool> decided(N+1, false);
    vector<int> dist(N+1, 2e9);

    //初期化
    dist[1] = 0;
    que.push(make_pair(dist[1], 1));

    while(!que.empty()){
        //次に決める頂点番号を取り出す(キューの内,最短距離のものから決める)
        int v = que.top().second;
        que.pop();

        //既に最短距離がわかっているなら飛ばす
        if(decided[v]) continue;

        for(auto nex : Graph[v]){
            int idx = nex.second;

            //vに隣接する頂点の長さを更新していく
            if(dist[v] + nex.first < dist[idx]){
                dist[idx] = dist[v] + nex.first;
                que.push(make_pair(dist[idx], idx));
            }
        }

        decided[v] = true;
    }

    /*ここまでA64と同じ
    for(int i = 1; i <= N; i++){
        if(decided[i]) cout << dist[i] << endl;
        else cout << -1 << endl;
    }*/

    //dpの復元同様にやる
    stack<int> ans;
    int now = N;
    while(now != 1){
        ans.push(now);

        for(auto prev : Graph[now]){
            if(dist[now] == dist[prev.second] + prev.first){
                now = prev.second;
                break;
            }
        }
    }
    ans.push(1);

    while(!ans.empty()){
        cout << ans.top() << " ";
        ans.pop();
    }
    return 0;
}