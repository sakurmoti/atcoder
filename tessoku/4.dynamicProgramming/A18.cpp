#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,S;
    cin >> N >> S;
    
    vector<int> A(N+1);
    for(int i = 1; i <= N; i++) cin >> A[i];

    //dp[i][j]をカードiまでを選んで合計をjにできるかどうか
    vector<vector<bool>> dp(N+1, vector<bool>(S+1, false));
    dp[0][0] = true; //0枚選ぶと合計0にできる

    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= S; j++){
            if(j==0) dp[i][j] = true;

            //i番目のカードを選ぶ場合
            if(i > 0 && j-A[i] >= 0 && dp[i-1][j-A[i]] == true) dp[i][j] = true;

            //i番目のカードを選ばない場合
            if(i > 0 && dp[i-1][j] == true) dp[i][j] = true;
        }
    }

    if(dp[N][S] == true) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}