#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define REP(i, n) for(int i = 0; i < (n); i++)
#define REP2(i, s, n) for(int i = s; i <= (n); i++)

int main(){
    int N; cin >> N;

    vector<vector<pair<int, ll>>> G(N+1);
    REP2(i,1,N){
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
        REP(i, G.size()){
            int next = G[v][i].first;
            ll cost = G[v][i].second;

            if(dist[next] > dist[v] + cost){
                dist[next] = dist[v] + cost;
                pque.push(make_pair(dist[next], next));
            }
        }
    }

    cout << dist[N] << endl;
    return 0;
}