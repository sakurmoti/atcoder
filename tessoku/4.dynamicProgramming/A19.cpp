#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,W;
    cin >> N >> W;

    vector<int> w(N+1),v(N+1);
    for(int i = 1; i <= N; i++){
        cin >> w[i] >> v[i];
    }

    //dp[i][j]を品物iまで選び、重さj以下にしたときの最大の価値とする
    vector<vector<long long>> dp(N+1, vector<long long>(W+1, 0));
    for(int i = 1; i <= N; i++){
        for(int j = 0; j<= W; j++){
            if(j-w[i] >= 0){
                //品物iを選べる場合
                dp[i][j] = max(dp[i-1][j-w[i]] + v[i], dp[i-1][j]);
            
            }else{
                //品物iを選ばない場合
                dp[i][j] = dp[i-1][j];
            
            }
        }
    }

    cout << dp[N][W] << endl;
    return 0;
}