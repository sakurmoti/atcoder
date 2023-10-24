#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

int main(){
    ll N,A,B,C;
    cin >> N >> A >> B >> C;
    vector<vector<ll>> D(N, vector<ll>(N));
    for(auto &_v : D) for(auto &_vv : _v) cin >> _vv;
    

    // 全部社用車として頂点1からdijkstra
    vector<ll> dist(N, 1e18);
    vector<bool> decided(N, false);
    dist[0] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>> > pque;
    pque.push(make_pair(dist[0], 0));

    while(!pque.empty()){
        int now = pque.top().second;
        pque.pop();

        if(decided[now]) continue;
        decided[now] = true;

        for(int i = 0; i < N; i++){
            int next = i;
            ll cost = D[now][next] * A; // 社用車

            if(dist[next] > dist[now] + cost){
                dist[next] = dist[now] + cost;
                if(decided[next]) continue;
                pque.push(make_pair(dist[next], next));
            }
        }
    }

    // 全部電車として頂点Nからdijkstra
    vector<ll> r_dist(N, 1e18);
    vector<bool> r_decided(N, false);
    r_dist[N-1] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>> > r_pque;
    r_pque.push(make_pair(dist[N-1], N-1));

    while(!r_pque.empty()){
        int now = r_pque.top().second;
        r_pque.pop();

        if(r_decided[now]) continue;
        r_decided[now] = true;

        for(int i = 0; i < N; i++){
            int next = i;
            ll cost = D[now][next] * B + C; // 電車

            if(r_dist[next] > r_dist[now] + cost){
                r_dist[next] = r_dist[now] + cost;
                if(r_decided[next]) continue;
                r_pque.push(make_pair(r_dist[next], next));
            }
        }
    }

    ll ans = 1e18;
    for(int i = 0; i < N; i++){
        ll d = dist[i] + r_dist[i];
        ans = min(d, ans);
    }
    cout << ans << endl;
    return 0;
}