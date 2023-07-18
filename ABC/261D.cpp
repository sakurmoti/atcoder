#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M; cin >> N >> M;
    vector<int> X(N+1);
    for(int i = 1; i <= N; i++) cin >> X[i];

    map<int,int> Y;
    for(int i = 0; i < M; i++){
        int c,y;
        cin >> c >> y;
        Y[c] = y;
    }

    // dp[i][j]をi番目まで見たときで、カウンタがjのときの最大値
    vector<vector<ll>> dp(N+1, vector<ll>(N+1,-1e10));
    for(int i = 0; i <= N; i++) dp[i][0] = 0;
    for(int i = 1; i <= N; i++){
        ll next = -1;
        for(int j = 1; j <= N; j++){
            if(i < j) break;

            //i番目で表
            dp[i][j] = dp[i-1][j-1]+X[i]+Y[j];
            
            //i番目で裏
            dp[i][0] = max(dp[i][0],dp[i-1][j]);
        }
    }

    // cout << endl; for(int i=0;i<=N;i++) for(int j=0;j<=N;j++) cout << dp[i][j] << " \n"[j==N];

    ll ans = -1;
    for(int j = 0; j <= N; j++){
        ans = max(ans, dp[N][j]);
    }
    cout << ans << endl;
    return 0;
}