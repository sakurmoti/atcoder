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
    int N; cin >> N;
    vector<int> A(N),B(N);
    int all = 0;
    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i];

        all += B[i];
    }

    if(all%3 != 0){
        cout << -1 << endl;
        return 0;
    }

    // dp[i][x][y] := i番目まで見たとき、チームの人数を(x, y, all-x-y)にするのに最低の変更回数
    int maxB = 510; // Bの総和の1/3の最大値
    vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(maxB, vector<int>(maxB, 1e9)));
    dp[0][0][0] = 0;

    for(int i = 0; i < N; i++){
        for(int x = 0; x < maxB; x++){
            for(int y = 0; y < maxB; y++){
                if(A[i] == 1){
                    if(x+B[i] < maxB) chmin(dp[i+1][x+B[i]][y], dp[i][x][y]);
                    if(y+B[i] < maxB) chmin(dp[i+1][x][y+B[i]], dp[i][x][y]+1);
                    chmin(dp[i+1][x][y], dp[i][x][y]+1);
                }else if(A[i] == 2){
                    if(x+B[i] < maxB) chmin(dp[i+1][x+B[i]][y], dp[i][x][y]+1);
                    if(y+B[i] < maxB) chmin(dp[i+1][x][y+B[i]], dp[i][x][y]);
                    chmin(dp[i+1][x][y], dp[i][x][y]+1);
                }else if(A[i] == 3){
                    if(x+B[i] < maxB) chmin(dp[i+1][x+B[i]][y], dp[i][x][y]+1);
                    if(y+B[i] < maxB) chmin(dp[i+1][x][y+B[i]], dp[i][x][y]+1);
                    chmin(dp[i+1][x][y], dp[i][x][y]);
                }
            }
        }
    }

    if(dp[N][all/3][all/3] > 1e8) cout << -1 << endl;
    else cout << dp[N][all/3][all/3] << endl;
    return 0;
}