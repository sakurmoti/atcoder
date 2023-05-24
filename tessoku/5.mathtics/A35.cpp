#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> A(N+1);
    for(int i = 1; i <= N; i++) cin >> A[i];

    //dp[i][j]を上からi段目、左からj番目のときの両者最善を尽くしたスコアとする
    vector<vector<int>> dp(N+1, vector<int>(N+1));
    for(int i = 1; i <= N; i++){
        //最下段にいるときはどう頑張ってもA[i]のスコアに
        dp[N][i] = A[i];
    }

    //1,3,5..の奇数段では太郎君(スコア最大化)、偶数段では次郎君(スコア最小化)
    for(int i = N-1; i > 0; i--){
        for(int j = 1; j <= i; j++){
            if(i%2 == 0){
                //スコア最小化
                dp.at(i).at(j) = min(dp.at(i+1).at(j), dp.at(i+1).at(j+1));

            }else{
                //スコア最大化
                dp.at(i).at(j) = max(dp.at(i+1).at(j), dp.at(i+1).at(j+1));

            }
        }
    }

    cout << dp.at(1).at(1) << endl;
    return 0;
}