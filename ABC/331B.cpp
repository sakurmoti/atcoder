#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    int S,M,L; cin >> S >> M >> L;

    vector<ll> dp(N+100, 1e18);
    dp[0] = 0;
    for(int i = 0; i <= N; i++){
        dp[i+6] = min(dp[i+6], dp[i] + S);
        dp[i+8] = min(dp[i+8], dp[i] + M);
        dp[i+12] = min(dp[i+12], dp[i] + L);
    }

    ll ans = 1e18;
    for(int i = N; i <= N+20; i++){
        ans = min(ans, dp[i]);
    }

    cout << ans << endl;
    return 0;
}