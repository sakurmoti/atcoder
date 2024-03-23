#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

constexpr int MOD = 998244353;

int main(){
    int N; cin >> N;
    vector<int> A(N+1),B(N+1);
    for(int i = 1; i <= N; i++){
        cin >> A[i] >> B[i];
    }

    // dp[i][j] := i番目のカードが表(j=0)または裏(j=1)の時の組合せ
    vector<vector<ll>> dp(N+1, vector<ll>(2, 0));
    dp[1][0] = 1;
    dp[1][1] = 1;

    // cppではtrueが1, falseが0
    for(int i = 2; i <= N; i++){
        dp[i][0] = dp[i-1][0] * (A[i-1] != A[i]) + dp[i-1][1] * (B[i-1] != A[i]);
        dp[i][1] = dp[i-1][0] * (A[i-1] != B[i]) + dp[i-1][1] * (B[i-1] != B[i]);

        dp[i][0] %= MOD;
        dp[i][1] %= MOD;
        // fprintf(stderr, "dp[%d] = %d | %d\n", i, dp[i][0], dp[i][1]);
    }

    cout << (dp[N][0] + dp[N][1]) % MOD << endl;
    return 0;
}