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
    int N; cin >> N;
    int Mg; cin >> Mg;
    vector<vector<bool>> G(N, vector<bool>(N, false));
    for(int i = 0; i < Mg; i++){
        int u,v; cin >> u >> v;
        u--; v--;
        G[u][v] = true;
        G[v][u] = true;
    }

    int Mh; cin >> Mh;
    vector<vector<bool>> H(N, vector<bool>(N, false));
    for(int i = 0; i < Mh; i++){
        int u,v; cin >> u >> v;
        u--; v--;
        H[u][v] = true;
        H[v][u] = true;
    }

    vector<vector<int>> A(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            cin >> A[i][j];
            A[j][i] = A[i][j];
        }
    }

    ll ans = 1e18;
    vector<int> nv(N); // iをnv[i]に変換
    iota(ALL(nv), 0);
    
    do{
        ll money = 0;
        
        for(int i = 0; i < N; i++){
            for(int j = i+1; j < N; j++){
                int ni = nv[i];
                int nj = nv[j];
                
                if(G[i][j] != H[ni][nj]){
                    money += A[ni][nj];
                }
            }
        }

        chmin(ans, money);
    }while(next_permutation(ALL(nv)));

    cout << ans << endl;
    return 0;
}