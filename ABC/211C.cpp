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

#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;

int main(){
    string S; cin >> S;
    int N = S.size();
    
    string T = "chokudai";
    int M = T.size();
    
    vector<vector<mint>> dp(N+1, vector<mint>(M+1, 0));
    for(int i = 0; i <= N; i++){
        dp[i][0] = 1;
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(S[i-1] == T[j-1]) dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[N][M].val() << endl;
    return 0;
}