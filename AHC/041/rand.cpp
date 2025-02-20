#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N,M,H; cin >> N >> M >> H;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    vector<vector<int>> G(N);
    for(int i = 0; i < M; ++i){
        int u,v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<pair<int, int>> P(N);
    for(int i = 0; i < N; ++i){
        int x,y; cin >> x >> y;
        P[i] = make_pair(x,y);
    }

    vector<int> leader(N, -1);
    mt19937 engine(0);
    for(int i = 0; i < N; i++){
        if(leader[i] != -1) continue;

        uniform_int_distribution<int> uid(0, G[i].size()-1);
        int j = uid(engine);
        leader[i] = i;
        leader[G[i][j]] = i;
    }

    for(int i = 0; i < N; i++){
        if(leader[i] == i){
            cout << -1 << " ";
        }else{
            cout << leader[i] << " ";
        }
    }
    return 0;
}