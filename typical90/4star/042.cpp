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
    ll K; cin >> K;

    if(K%9 != 0){
        // 9の倍数 = 各桁の総和が9の倍数
        cout << 0 << endl;
        return 0;
    }

    vector<mint> dp(K+1, 0);
    dp[0] = 1;
    for(int i = 1; i <= K; i++){
        for(int j = 1; j <= 9; j++){
            if(i-j >= 0) dp[i] += dp[i-j];
        }
    }

    cout << dp[K].val() << endl;
    return 0;
}