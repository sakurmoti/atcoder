#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 1'000'000'007;

int main(){
    int N,M;
    cin >> N >> M;

    vector<ll> dp(N+1, 0);
    dp[0] = 1;
    for(int i = 0; i < M; i++){
        int a; cin >> a;
        dp[a] = -1e10;
    }

    for(int i = 1; i <= N; i++){
        if(dp[i] < 0) continue;
        
        if(i == 1){
            dp[i] += dp[i-1];

        }else{
            if(dp[i-1] < 0 && dp[i-2] < 0){
                //2段壊れているので登れない
                cout << 0 << endl;
                return 0;
            }

            if(dp[i-1] > 0) dp[i] += dp[i-1];
            if(dp[i-2] > 0) dp[i] += dp[i-2];

            dp[i] %= MOD;
        }
    }

    cout << dp[N] << endl;
    return 0;
}