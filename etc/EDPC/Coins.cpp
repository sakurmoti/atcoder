#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    vector<double> p(N+1);
    for(int i = 1; i <= N; i++){
        cin >> p[i];
    }

    // dp[i][j] := i番目まで見てj個表が出る確率
    vector<vector<double>> dp(N+1, vector<double>(N+1, 0.0));
    dp[0][0] = 1.0;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= N; j++){
            if(j > 0) dp[i][j] += (dp[i-1][j-1] * p[i]);
            dp[i][j] += (dp[i-1][j] * (1-p[i]));
        }
    }

    double ans = 0;
    for(int j = 0; j <= N; j++){
        if(j > N-j){
            ans += dp[N][j];
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}