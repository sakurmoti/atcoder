#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N1,N2,M;
    cin >> N1 >> N2 >> M;
    vector<vector<int>> G(N1+N2+1);
    for(int i = 0; i < M; i++){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    //1から最も遠い頂点とN1+N2から最も遠い頂点を結べば最長経路
    vector<int> dist(N1+N2+1, -1);
    queue<int> que;
    dist[1] = 0;
    dist[N1+N2] = 0;
    que.push(1);
    que.push(N1+N2);
    while(!que.empty()){
        int v = que.front();
        que.pop();

        for(auto u : G[v]){
            if(dist[u] != -1) continue;
            dist[u] = dist[v]+1;
            que.push(u);
        }
    }

    int path1=-1, pathN=-1;
    for(int i = 1; i <= N1+N2; i++){
        if(i <= N1) path1 = max(path1, dist[i]);
        else pathN = max(pathN, dist[i]);
    }
    // printf("path1 = %d, pathN = %d\n",path1, pathN);
    cout << path1 + pathN + 1 << endl;
    return 0;
}