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
    int H,W,N,h,w;
    cin >> H >> W >> N >> h >> w;

    vector<vector<int>> A(H, vector<int>(W));
    vector<int> cnt(N, 0);
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> A[i][j];
            A[i][j]--;
            if(!isRange(i,0,h) || !isRange(j,0,w)) cnt[A[i][j]]++;
        }
    }

    vector<vector<int>> ans(H-h+1, vector<int>(W-w+1, 0));
    for(int i = 0; i <= H-h; i++){
        for(int j = (i%2==0 ? 0 : W-w); (i%2==0 ? j <= W-w : j >= 0); (i%2==0 ? j++ : j--) ){
            // cout << i << " " << j << endl;

            if(i%2==0 && j!=0){
                for(int k = 0; k < h; k++){
                    cnt[A[i+k][j-1]]++;
                    cnt[A[i+k][j+w-1]]--;
                }
            }else if(i%2!=0 && j!=W-w){
                for(int k = 0; k < h; k++){
                    cnt[A[i+k][j+w]]++;
                    cnt[A[i+k][j]]--;
                }
            }

            int buf = 0;
            for(int k = 0; k < N; k++){
                if(cnt[k] > 0) buf++;
            }
            ans[i][j] = buf;


            // cout << i << " " << j << endl;
            // for(auto &_v : cnt) cout << _v << " "; cout << endl;
            // cout << endl;
        }

        if(i%2==0 && i!=H-h){
            for(int k = 1; k <= w; k++){
                cnt[A[i][W-k]]++;
                cnt[A[i+h][W-k]]--;
            }
        }else if(i%2!=0 && i!=H-h){
            for(int k = 0; k < w; k++){
                cnt[A[i][k]]++;
                cnt[A[i+h][k]]--;
            }
        }
    }

    for(auto &_v : ans){ for(auto &_vv : _v) cout << _vv << " "; cout << endl; }
    return 0;
}