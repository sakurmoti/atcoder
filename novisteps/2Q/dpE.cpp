#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N,W; cin >> N >> W;
    
    // dp[j] := 価値がjのときの最小の重さ
    vector<ll> dp(2e5, 1e18);
    dp[0] = 0;
    for(int i = 1; i <= N; i++){
        auto ndp = dp;
        int w,v; cin >> w >> v;
        
        for(int j = v; j <= 1e5; j++){
            bool c = chmin(ndp[j], dp[j-v]+w);
            // if(c) cout << "change\n";
        }

        dp = ndp;
        // for(auto &_v : dp) if(_v < 1e17) cout << _v << " "; cout << endl;
    }

    ll ans = 0;
    for(ll i = 0; i <= 1e5; i++){
        if(dp[i] <= W) chmax(ans, i);
    }

    cout << ans << endl;
    return 0;
}