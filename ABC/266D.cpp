#include <bits/stdc++.h>
using namespace std;

int main(){
    //基本のdp！！
    int N;
    cin >> N;
    
    //X[i]は時刻iにすぬけくんがでてくる座標とすると処理が楽。A[i]も同様
    vector<int> T(N),X(100010),A(10010);
    for(int i = 0; i < N; i++){
        cin >> T[i];
        cin >> X[T[i]] >> A[T[i]];
    }

    /*dp[x][t]は時刻tに座標xにいるときの大きさの合計の最大値とする
    dp漸化式は時刻t-1からtでxに移動できるのはx-1,x,x+1にいるとき
    ゆえにこの中からの最大値+[x][t]に移動したとき新たにgetできるすぬけくんの大きさになる
    dp[x][t] = max(dp[x-1][t-1], dp[x][t-1], dp[x+1][t-1]) + 時刻tで座標xにいたらゲットできるすぬけくん*/
    vector<vector<long long>> dp(10,vector<long long>(100010,0));
    
    for(int i = 0; i < N; i++){
        //dp[x][t] = max(dp[x-1][t-1])
    }

    return 0;
}