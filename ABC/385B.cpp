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
    int H,W,X,Y; cin >> H >> W >> X >> Y;
    X--; Y--;
    vector<string> S(H);
    for(auto &_v : S) cin >> _v;

    string T; cin >> T;
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    for(int i = 0; i < T.size(); i++){
        char c = T[i];

        if(c == 'U'){
            if(isRange(X-1, 0, H) && S[X-1][Y] != '#'){
                X--;
            }
        }else if(c == 'D'){
            if(isRange(X+1, 0, H) && S[X+1][Y] != '#'){
                X++;
            }
        }else if(c == 'L'){
            if(isRange(Y-1, 0, W) && S[X][Y-1] != '#'){
                Y--;
            }
        }else if(c == 'R'){
            if(isRange(Y+1, 0, W) && S[X][Y+1] != '#'){
                Y++;
            }
        }

        visited[X][Y] = true;
    }

    int ans = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(visited[i][j] && S[i][j] == '@'){
                ans++;
            }
        }
    }
    cout << X+1 << " " << Y+1 << " " << ans << endl;

    return 0;
}