#include <bits/stdc++.h>
using namespace std;

int main(){
    long long X,Y,Z;
    cin >> X >> Y >> Z;
    string S;
    cin >> S;

    int N = S.size();
    
    //dp[i][j]はi文字目まで最短で何秒で書けるか(CapsLockはj=0でオフ、j=1でオン)
    //1-idxにすることに注意
    vector<vector<long long>> dp(N+10, vector<long long>(10,0));
    dp[0][0] = 0;
    dp[0][1] = Z;
    for(int i = 0; i < N; i++){
        if(S[i] == 'A'){
            dp[i+1][0] = min({dp[i][0]+Y, dp[i][1]+X+Z, dp[i][1]+Z+Y});
            dp[i+1][1] = min({dp[i][1]+X, dp[i][0]+Y+Z, dp[i][0]+Z+X});
        }

        if(S[i] == 'a'){
            dp[i+1][0] = min({dp[i][0]+X, dp[i][1]+Z+X, dp[i][1]+Y+Z});
            dp[i+1][1] = min({dp[i][1]+Y, dp[i][0]+Z+Y, dp[i][0]+X+Z});
        }
    }

    cout << min(dp[N][0], dp[N][1]) << endl;
    return 0;
}