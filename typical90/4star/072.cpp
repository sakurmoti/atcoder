#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main(){
    int H,W; cin >> H >> W;
    vector<string> S(H);
    for(auto &_v : S) cin >> _v;

    auto rec = [&](auto self, const int sy, const int sx, int y, int x, int l, vector<vector<bool>> visited) -> int {
        int ret = 0;
        for(int d = 0; d < 4; d++){
            int ny = y + dy[d];
            int nx = x + dx[d];
            if(ny == sy && nx == sx){
                return max(ret, l+1);
            }
            if(!isRange(nx, 0, W) || !isRange(ny, 0, H) || visited[ny][nx] || S[ny][nx] == '#') continue;

            visited[y][x] = true;
            chmax(ret, self(self, sy,sx, ny,nx, l+1, visited));
        }

        return ret;
    };

    int ans = -1;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j] == '#') continue;
            chmax(ans, rec(rec, i,j, i,j, 0, vector(H, vector(W, false))));
        }
    }

    if(ans > 2) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}