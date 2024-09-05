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
    ll N,K; cin >> N >> K;
    vector<int> X(N),A(N);
    for(auto &_v : X) cin >> _v;
    for(auto &_v : A) cin >> _v;

    for(int i = 0; i < N; i++){
        X[i]--;
    }
    
    // dp[i][j] := 2^i回操作したとき、数列のi番目はA[dp[i][j]]なる定義
    vector<vector<int>> dp(64, vector<int>(N, 0));
    for(int j = 0; j < N; j++){
        dp[0][j] = X[j];
    }

    // for(auto &_v : dp[0]) cout << _v << " "; cout << endl;

    for(int i = 1; i < 60; i++){
        for(int j = 0; j < N; j++){
            dp[i][j] = dp[i-1][dp[i-1][j]];
            
            // cout << dp[i][j] << " ";
        }
        // cout << "\n";
    }

    bitset<64> bits(K);
    vector<int> ans = A;
    for(int b = 0; b < 60; b++){
        if(bits.test(b)){
            for(int i = 0; i < N; i++){
                A[i] = ans[dp[b][i]];
            }
            ans = A;
        }
    }

    for(auto &_v : ans) cout << _v << " "; cout << endl;
    return 0;
}