#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N; cin >> N;
    vector<int> P(N);
    for(auto &_v : P) cin >> _v;
    
    // p点の最大が小さいことに注目する
    // dp[i][j] := i番目まで見たとき、得点jを達成できるか
    vector<vector<bool>> dp(N+1, vector<bool>(1e5, false));
    for(int i = 0; i <= N; i++) dp[i][0] = true;

    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= 1e4; j++){
            if(dp[i-1][j]){
                dp[i][j] = true;
                dp[i][j+P[i-1]] = true;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < 1e5; i++){
        if(dp[N][i]){
            ans++;
            // cout << i << endl;
        }
    }

    cout << ans << endl;
    return 0;
}