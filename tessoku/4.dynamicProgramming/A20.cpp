#include <bits/stdc++.h>
using namespace std;

int main(){
    string S,T;
    cin >> S >> T;

    //文字列を1-idxに
    S.insert(S.begin(), ' ');
    T.insert(T.begin(), ' ');

    //dp[i][j]をSをi文字目、Tをj文字目まで見たときの共通部分列の長さとする
    vector<vector<int>> dp(S.size(), vector<int>(T.size(), 0));
    dp[0][0] = 0;
    for(int i = 1; i < S.size(); i++){
        for(int j = 1; j < T.size(); j++){
            if(S.at(i) == T.at(j)){
                //文字が同じなら使ったほうがよい
                dp[i][j] = dp[i-1][j-1] + 1;
            
            }else{
                //文字が同じでないならSかTどちらかのその文字は使わない
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

            }
        }
    }

    cout << dp[S.size()-1][T.size()-1] << endl;
    return 0;
}