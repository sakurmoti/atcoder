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
    vector<vector<ll>> dist(N, vector<ll>(N, 1e18));
    for(int i = 0; i < N; i++){
        dist[i][i] = 0;
    }

    for(int i = 0; i < M; i++){
        int u,v,t; cin >> u >> v >> t;
        u--; v--;
        dist[u][v] = t;
    }

    ll sum = 0;
    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                chmin(dist[i][j], dist[i][k] + dist[k][j]);
                if(dist[i][j] < 1e17) sum += dist[i][j];

                // printf("f(%d,%d,%d) = %lld\n",i,j,k, (dist[i][j] < 1e17 ? dist[i][j] : 0));
            }
        }
    }
    cout << sum << endl;
    return 0;
}