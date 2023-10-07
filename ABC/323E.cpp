#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

int main(){
    int n,x; cin >> n >> x;
    vector<int> T(n);
    for(int i = 0; i < n; i++){
        cin >> T[i];
    }

    mint N(n),X(x);


    // dp[i] := i秒に何らかの曲が再生を終了した確率
    vector<mint> dp(1e5, 0);
    dp[0] = 1;
    for(int i = 0; i <= x; i++){
        
        for(int j = 0; j < n; j++){
            dp[i+T[j]] += dp[i] * (1/N);
        }

    }

    // for(int j = 0; j <= x; j++){
    //     cout << dp[j].val() << endl;
    // }

    mint ans = 0;
    for(int i = 0; i < T[0]; i++){
        // (X-T[0], X] の区間で1の曲が流れればよい
        if(x-i < 0) break;
        ans += dp[x-i] * (1/N);
    }

    cout  << ans.val() << endl;

    return 0;
}