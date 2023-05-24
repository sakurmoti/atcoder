#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int N,M;
vector<vector<int>> Graph;

void dijkstra(int x, vector<int> &cur){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p_que;
    vector<bool> decide(N+1, false);

    cur[x] = 0;
    p_que.push(make_pair(cur[x], x));

    while(!p_que.empty()){
        int pos = p_que.top().second;
        p_que.pop();

        if(decide[pos]) continue;

        decide[pos] = true;
        for(int i = 0; i < Graph[pos].size(); i++){
            int next = Graph[pos][i];

            if(cur[next] > cur[pos] + 1){
                cur[next] = cur[pos] + 1;
                p_que.push(make_pair(cur[next], next));
            }
        }
    }
}

int main(){
    cin >> N >> M;

    int u,v;
    Graph.resize(N+1);
    for(int i = 0; i < M; i++){
        cin >> u >> v;

        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    vector<vector<int>> dist(N+1, vector<int>(N+1,1e8));
    for(int i = 1; i <= N; i++){
        dijkstra(i, dist[i]);
    }

    int K; cin >> K;
    vector<int> p(K),d(K);
    vector<int> ans(N+1, 0);
    for(int i = 0; i < K; i++){
        cin  >> p[i] >> d[i];

        for(int j = 1; j <= N; j++){
            if(dist[p[i]][j] == d[i]){
                ans[j] = 1;
            }
        }
    }

    for(int i = 1; i <= N; i++){
        cout << ans[i];
    }

    return 0;
}