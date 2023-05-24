#include <bits/stdc++.h>
using namespace std;

int main(){
    //基本のdp
    int N,M;
    cin >> N >> M;
    
    vector<long long> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    /*dp[i][j]をiまでのうちj個部分列に選んだ時のΣ(i*B[i])の最大値とする
    例えばA={5,4,-1,8}なら|5|4|-1|8|のように仕切れるのでiは0,1,2,3,4まで
    iが0のとき、0個選ぶのは0で表せるが、1個選ぶのはできないのでマイナス無限を入れる
    答えはマイナスになりうるので0を入れないよう注意
    このとき、dp遷移図は
    (A[i]を選ばない時) dp[i+1][j] = dp[i][j]
    (A[i]を選ぶとき) dp[i+1][j] = dp[i][j-1] + j*A[i-1]
    このうち大きい方をdp[i][j]として更新すればよい*/
    const long long INF = 1e18;
    vector<vector<long long>> dp(N+2, vector<long long>(M+1,-INF));
    dp[0][0] = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= M; j++){
            //選ばない場合
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);

            //選ぶ場合
            if(j>0) dp[i+1][j] = max(dp[i+1][j], dp[i][j-1] + j*A[i]);
        }
    }

    cout << dp[N][M] << endl;


    return 0;
}