#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

#include <atcoder/all>
using namespace atcoder;

int main(){
    int N,M; cin >> N >> M;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    // スコアが0より大きいパスだけ探せばよい
    // A[u] < A[v]なるパスはu -> vの有向パスを持つとする
    // A[u] = A[v]かつ隣接する場合、頂点同一視を行う
    vector<vector<pair<int, int>>> G(3e5);
    dsu d(N);
    for(int i = 0; i < M; i++){
        int u,v; cin >> u >> v;
        u--; v--;
        
        if(A[u] < A[v]) G[A[u]].push_back(make_pair(u,v));
        else if(A[u] == A[v]) d.merge(u, v);
        else G[A[v]].push_back(make_pair(v,u));
    }

    // dp[v] := 頂点0からvに行くときの最高スコア
    // グラフをAの小さい値順にたどればよい
    vector<int> dp(N, -1e9);
    dp[d.leader(0)] = 1; // 頂点0(と同一視した頂点)は初期化

    for(int i = 0; i < G.size(); i++){
        for(int j = 0; j < G[i].size(); j++){
            int u,v; // u->vの有向パスを示す
            tie(u, v) = G[i][j];
            u = d.leader(u);
            v = d.leader(v);

            if(dp[u] > 0){
                dp[v] = max(dp[v], dp[u]+1);
            }
        }
    }

    cout << max(0, dp[d.leader(N-1)]) << endl;
    return 0;
}