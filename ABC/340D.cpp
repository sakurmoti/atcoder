#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;

    vector<vector<pair<int, ll>>> G(N+1);
    for(int i = 1; i <= N-1; i++){
        ll A,B,X;
        cin >> A >> B >> X;

        G[i].push_back(make_pair(i+1, A));
        G[i].push_back(make_pair(X, B));
    }

    vector<bool> decided(N+1, false);
    vector<ll> dist(N+1, 1e18);

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pque;
    pque.push({0, 1});
    dist[1] = 0;
    while(!pque.empty()){
        auto [d, v] = pque.top(); pque.pop();
        if(decided[v]) continue;
        decided[v] = true;
        for(int i = 0; i < G[v].size(); i++){
            int next = G[v][i].first;
            ll cost = G[v][i].second;

            if(dist[next] > dist[v] + cost){
                dist[next] = dist[v] + cost;
                pque.push(make_pair(dist[next], next));
            }
        }

        if(decided[N]) break;
    }

    // for(int i = 1; i <= N; i++) cout << dist[i] << " ";
    cout << dist[N] << endl;
    return 0;
}