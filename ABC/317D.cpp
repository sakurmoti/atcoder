#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;

    vector<int> X(N+1),Y(N+1),Z(N+1);
    int sum = 0; //選挙区全体
    for(int i = 1; i <= N; i++){
        cin >> X[i] >> Y[i] >> Z[i];
        sum += Z[i];
    }

    int border = sum/2 + 1;

    //議席が過半数以上になる最小のコストを調べたい
    //dp[i][j] := i番目の選挙区まで見たときの、議席をj以上にするための最小のコスト
    vector<vector<ll>> dp(N+1, vector<ll>(1e6, 1e15));
    for(int i = 0; i <= N; i++){
        dp[i][0] = 0;
    }

    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= sum; j++){
            int cost = max(0, Y[i] - (X[i]+Y[i])/2 );
            int price = Z[i];

            //この選挙区の議席を放棄
            dp[i][j] = min(dp[i][j], dp[i-1][j]);

            //この選挙区の議席を獲得
            if(j-price >= 0){
                dp[i][j] = min(dp[i][j], dp[i-1][j - price] + cost);
            }

        }
    }

    ll ans = 1e15;
    for(int i = border; i <= sum; i++){
        // cout << dp[N][i] << endl;
        ans = min(ans, dp[N][i]);
    }
    cout << ans << endl;
    return 0;
}