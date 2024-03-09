#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,M; cin >> N >> M;
    
    // 駅Nから逆方向に考える
    struct train{
        ll l,d,k,c,to,from;
        train(ll _l, ll _d, ll _k, ll _c, ll _to, ll _from)
        : l(_l), d(_d), k(_k), c(_c), to(_to), from(_from) {}

        // toに到着できる出発時刻のうち一番早いものを求める
        // limitに間に合わないなら-1を返却
        ll get_latest_time(ll limit){
            // 最初の電車
            if(limit < l + c) return -1;
            
            ll ok = 0;
            ll ng = k;
            while(abs(ok-ng) >= 2){
                ll mid = (ok+ng)/2;
                if(limit < l + d*mid + c){
                    ng = mid;
                }else{
                    ok = mid;
                }
            }

            return l + d*ok;
        }
    };
    vector<vector<train>> G(N);
    for(int i = 0; i < M; i++){
        ll l,d,k,c,A,B;
        cin >> l >> d >> k >> c >> A >> B;

        A--; B--;
        G[B].push_back(train(l,d,k,c,A,B));
    }

    priority_queue<pair<ll, int>> pque;
    pque.push(make_pair(9e18, N-1));
    vector<ll> dijkstra(N, 9e18);
    vector<bool> decided(N, false);
    while(!pque.empty()){
        auto [limit,v] = pque.top();
        pque.pop();
        if(decided[v]) continue;
        decided[v] = true;
        dijkstra[v] = limit;

        for(int i = 0; i < G[v].size(); i++){
            auto next_train = G[v][i];
            ll time = next_train.get_latest_time(limit);
            // cout << time << endl;
            if(time >= 0){
                pque.push(make_pair(time, next_train.to));
            }
        }
    }
    
    for(int i = 0; i < N-1; i++){
        if(decided[i]) cout << dijkstra[i] << "\n";
        else cout << "Unreachable\n";
    }
    return 0;
}