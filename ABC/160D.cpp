#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,X,Y; cin >> N >> X >> Y;
    vector<vector<int>> G(N);
    for(int i = 0; i < N-1; i++){
        G[i].push_back(i+1);
        G[i+1].push_back(i);
    }
    G[X-1].push_back(Y-1);
    G[Y-1].push_back(X-1);

    vector<int> ans(N+10, 0);
    auto bfs = [&](int v) -> void {
        queue<pair<int, int>> que;
        que.push(make_pair(v, 0));

        vector<int> dist(N,1e9);
        while(!que.empty()){
            int now = que.front().first;
            int d = que.front().second;
            que.pop();

            if(dist[now] <= d) continue;
            dist[now] = d;

            for(int i = 0; i < G[now].size(); i++){
                int nex = G[now][i];
                que.push(make_pair(nex, dist[now]+1));
            }
        }

        for(int i = 0; i < N; i++){
            ans[dist[i]]++;
        }
    };

    for(int i = 0; i < N; i++){
        bfs(i);
    }

    for(int i = 1; i < N; i++){
        cout << ans[i]/2 << endl;
    }
    return 0;
}