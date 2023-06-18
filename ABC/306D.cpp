#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<ll> X(N+1,0),Y(N+1,0);
    for(int i = 1; i <= N; i++){
        cin >> X[i] >> Y[i];
    }

    //dp[i][j] := i品目まで見たときの最大のおいしさ(j=0で普通、j=1で毒)
    vector<vector<ll>> dp(N+1, vector<ll>(2,0));
    dp[0][0] = 0;
    dp[0][1] = 0;
    for(int i = 1; i <= N; i++){
        if(X[i] == 0){
            dp[i][0] = max({dp[i-1][0]+Y[i], dp[i-1][1]+Y[i], dp[i-1][0]});
            dp[i][1] = dp[i-1][1];
        }else{
            dp[i][0] = dp[i-1][0];
            dp[i][1] = max(dp[i-1][0]+Y[i], dp[i-1][1]);
        }
    }

    cout << max(dp[N][0], dp[N][1]) << endl;
    return 0;
}