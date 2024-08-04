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
    int N,X,Y; cin >> N >> X >> Y;
    vector<int> A(N+1),B(N+1);
    for(int i = 1; i <= N; i++){
        cin >> A[i] >> B[i];
    }

    // dp[i][j][k] := i番目まで見たとき、食べた料理数がj、甘さの合計がkのとき、しょっぱさの合計
    vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(N+1, vector<int>(X+1, 1e9)));
    dp[0][0][0] = 0;

    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= N; j++){
            for(int k = 0; k <= X; k++){
                chmax(dp[i][j][k], dp[i-1][j][k]);

                chmax(dp[i][j+1][max(X,k+A[i])], dp[i][j][k] + B[i]);
            }
        }
    }

    int ans = 0;
    for(int j = 0; j <= N; j++){
        for(int k = 0; k <= X; k++){
            if(dp[N][j][k] > Y){
                chmax(ans, j);
            }
        }
    }

    cout << ans << endl;
    return 0;
}