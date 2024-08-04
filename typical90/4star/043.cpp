#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int H,W; cin >> H >> W;
    int sx,sy,gx,gy;
    cin >> sy >> sx >> gy >> gx;
    sx--; sy--;
    gx--; gy--;

    vector<vector<char>> S(H, vector<char>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> S[i][j];
        }
    }

    vector<vector<vector<int>>> ans(H, vector<vector<int>>(W, vector<int>(4, 1e9)));
    for(int i = 0; i < 4; i++) ans[sy][sx][i] = 0;
    
    constexpr int dx[4] = {0,1,0,-1};
    constexpr int dy[4] = {1,0,-1,0};
    deque<tuple<int,int,int>> deq;
    for(int i = 0; i < 4; i++) deq.push_front(make_tuple(sx,sy,i));
    
    while(!deq.empty()){
        auto[x,y,d] = deq.front();
        deq.pop_front();

        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(isRange(nx,0,W) && isRange(ny,0,H) && S[ny][nx] != '#'){
                if(d==dir){
                    if(chmin(ans[ny][nx][dir], ans[y][x][d])){
                        deq.push_front(make_tuple(nx,ny,dir));
                    }

                }else{
                    if(chmin(ans[ny][nx][dir], ans[y][x][d]+1)){
                        deq.push_back(make_tuple(nx,ny,dir));
                    }
                }
            }
        }
    }

    // for(auto &_v : ans){ for(auto &_vv : _v) cout << *min_element(ALL(_vv)) << " "; cout << endl; }

    cout << *min_element(ALL(ans[gy][gx])) << endl;
    return 0;
}