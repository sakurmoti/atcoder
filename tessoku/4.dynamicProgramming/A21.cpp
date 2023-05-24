#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> P(N+10,-1e5),A(N+10,-1e5);
    for(int i = 1; i <= N; i++){
        cin >> P.at(i) >> A.at(i);
    }
    
    //左端か右端から取るので残るブロックは必ず連番となる
    //そこでdp[L][R]をL番目からR番目まで残っているときの最大の点数とする
    vector<vector<int>> dp(N+10, vector<int>(N+10, -1e5));
    dp.at(1).at(N) = 0; //何も取り除いていないので得点は0

    //dp[L][R]を求めるにはdp[L-1][R]とdp[L][R+1]が求まっている必要があるので
    //R-Lが大きい順に計算する
    for(int len = N-2; len >= 0; len--){
        for(int L = 1; L <= N-len; L++){
            int R = L + len;

            //左端のブロックを取る場合(L-1番目のブロックを取る)
            int scoreL = 0;
            if(L <= P.at(L-1) && P.at(L-1) <= R) scoreL = A.at(L-1);

            //右端のブロックを取る場合(R+1番目のブロックを取る)
            int scoreR = 0;
            if(L <= P.at(R+1) && P.at(R+1) <= R) scoreR = A.at(R+1);

            //条件分岐
            if(L == 1){
                dp.at(L).at(R) = dp.at(L).at(R+1) + scoreR;

            }else if(R == N){
                dp.at(L).at(R) = dp.at(L-1).at(R) + scoreL;

            }else{
                dp.at(L).at(R) = max(dp.at(L-1).at(R)+scoreL, dp.at(L).at(R+1)+scoreR);

            }

        }
    }

    //P[i] != iからL==Rのとき得点は増えないのでdp[i][i]の最大値が答え
    int ans = -1;
    for(int i = 1; i <= N; i++) ans = max(ans, dp.at(i).at(i));
    cout << ans << endl;
    
    return 0;
}