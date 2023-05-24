#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    vector<vector<pair<int,int>>> Graph(N+1);
    for(int i = 0; i < M; i++){
        int a,b,c;
        cin >> a >> b >> c;

        Graph[a].push_back(make_pair(c,b)); //第1引数が重さ、第2引数が頂点番号
        Graph[b].push_back(make_pair(c,a));
    }

    vector<int> dist(N+1, 1e9);
    vector<bool> decided(N+1, false); //最小が確定した頂点
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> que; //第1引数が最短距離、第2引数が頂点番号
    que.push(make_pair(0,1));
    dist[1] = 0;
    while(!que.empty()){
        pair<int,int> v = que.top();
        que.pop();

        if(decided[v.second]) continue;

        for(auto u : Graph.at(v.second)){
            int idx = u.second;

            if(dist[idx] >  v.first + u.first){
                dist[idx] = v.first + u.first;
                que.push(make_pair(dist[idx], idx));
            }
        }
        decided[v.second] = true;
    }

    for(int i = 1; i <= N; i++){
        if(1e9 == dist[i]) cout << -1 << endl;
        else cout << dist[i] << endl;
    }
    return 0;
}