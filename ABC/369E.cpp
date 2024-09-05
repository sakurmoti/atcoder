#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
struct Point{int x, y;};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N,M; cin >> N >> M;

    vector<tuple<int, int, int>> bridge(M);
    vector<vector<pair<int, ll>>> G(N+M);
    for(int i = 0; i < M; i++){
        int u,v,t;
        cin >> u >> v >> t;
        u--; v--;

        bridge[i] = make_tuple(u, v, t);
        G[u].push_back(make_pair(v, t));
        G[v].push_back(make_pair(u, t));
    }

    // Warshall-floyd
    vector<vector<ll>> dist(N, vector<ll>(N, 1e18));
    for(int i = 0; i < N; i++){
        dist[i][i] = 0;
        for(int j = 0; j < G[i].size(); j++){
            auto[nex, cost] = G[i][j];
            chmin(dist[i][nex], cost);
            chmin(dist[nex][i], cost);
        }
    }

    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                chmin(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    // for(auto &_v : dist){ for(auto &_vv : _v) cout << _vv << " "; cout << endl; }

    int Q; cin >> Q;
    while(Q--){
        int K; cin >> K;
        vector<int> B(K);
        for(int i = 0; i < K; i++){
            cin >> B[i];
            B[i]--;
        }

        sort(ALL(B));
        
        ll ans = 1e18;
        do
        {
            for(int b = 0; b < (1<<K); b++){
                bitset<5> bits(b); // 0ならu->v方向、1が立ったらv->u方向
                int now = 0;
                ll buf = 0;
                for(int i = 0; i < K; i++){
                    auto[u,v,cost] = bridge[B[i]];
                    if(!bits.test(i)){
                        buf += dist[now][u]; // uまで
                        buf += cost; //橋を渡る
                        now = v;

                    }else{
                        buf += dist[now][v];
                        buf += cost;
                        now = u;
                    
                    }
                }
                buf += dist[now][N-1];

                chmin(ans, buf);
            }
        } while (next_permutation(ALL(B)));
        
        cout << ans << endl;
    }
    return 0;
}