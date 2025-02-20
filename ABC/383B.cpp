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
    int H,W,D; cin >> H >> W >> D;
    vector<string> S(H);
    for(auto &_v : S) cin >> _v;

    int ans = 0;
    for(int y1 = 0; y1 < H; y1++){
        for(int x1 = 0; x1 < W; x1++){
            if(S[y1][x1] == '#') continue;

            int cnt1 = 0;
            auto cp = S;

            for(int i = 0; i < H; i++){
                for(int j = 0; j < W; j++){
                    if(abs(i-y1) + abs(j-x1) <= D && cp[i][j] == '.'){
                        cnt1++;
                        cp[i][j] = '$';
                    }
                }
            }
            
            for(int y2 = 0; y2 < H; y2++){
                for(int x2 = 0; x2 < W; x2++){
                    if(cp[y2][x2] == '#') continue;

                    int cnt2=0;
                    for(int i = 0; i < H; i++){
                        for(int j = 0; j < W; j++){
                            if(abs(i-y2) + abs(j-x2) <= D && cp[i][j] == '.'){
                                cnt2++;
                            }
                        }
                    }

                    chmax(ans, cnt1+cnt2);
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}