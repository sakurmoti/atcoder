#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
struct Point{int x,y; Point(){}; Point(int _x, int _y):x(_x),y(_y){}};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int H,W,K;
    cin >> H >> W >> K;

    vector<string> S(H);
    for(auto &_v : S) cin >> _v;

    ll ans = 0;
    auto dfs = [&](auto self, int y, int x, set<int> &path, int limit) {
        if(limit <= 0){
            ans++;
            // for(auto &_v : path) cout << _v << " "; cout << endl;
            return;
        }

        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(path.contains(ny*W+nx)) continue;

            if(isRange(ny, 0, H) && isRange(nx, 0, W) && S[ny][nx] != '#'){
                path.insert(ny*W + nx);
                self(self, ny, nx, path, limit-1);
                path.erase(ny*W + nx);
            }
        }
    };

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j] == '#') continue;

            set<int> buf;
            buf.insert(i*W + j);
            dfs(dfs, i, j, buf, K);
        }
    }

    cout << ans << endl;
    return 0;
}