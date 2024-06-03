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
    int N,L; cin >> N >> L;

    vector<mint> dp(N+1, 0);
    dp[0] = 1;
    for(int i = 1; i <= N; i++){
        dp[i] += dp[i-1];
        if(i - L >= 0) dp[i] += dp[i-L];
    }

    cout << dp[N].val() << endl;
    return 0;
}