#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;

int main(){
    int N; cin >> N;
    string S; cin >> S;
    S.insert(S.begin(), ' ');

    string T = " atcoder";
    int M = T.size() -1;

    // dp[i][j] := i文字目まで見たとき、"atcoder"のj文字目まで一致する組合せ
    vector<vector<mint>> dp(N+1, vector<mint>(M+1, 0));
    for(int i = 0; i <= N; i++){
        dp[i][0] = 1;
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(S[i] == T[j]) dp[i][j] += dp[i-1][j-1];
            dp[i][j] += dp[i-1][j];
        }
    }

    // for(auto u : dp){
    //     for(auto v : u){
    //         cout << v.val() << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[N][M].val() << endl;
    return 0;
}