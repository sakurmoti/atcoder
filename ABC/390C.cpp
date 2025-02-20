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
    int H,W; cin >> H >> W;
    vector<string> S(H);
    for(auto &_v : S) cin >> _v;

    vector<pair<int, int>> black;
    int l=W,r=-1,u=H,d=-1;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j] == '#'){
                black.push_back({i, j});
                
                chmin(l, j);
                chmax(r, j);
                chmin(u, i);
                chmax(d, i);
            }
        }
    }

    // printf("(%d,%d),(%d,%d)\n", u, l, d, r);
    
    for(int i = u; i <= d; i++){
        for(int j = l; j <= r; j++){
            if(S[i][j] == '.'){
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}