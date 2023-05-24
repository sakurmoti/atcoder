#include <bits/stdc++.h>
using namespace std;

template<class T>
void chmax(T &a,T b){
    if(a < b) a = b;
}

int main(){
    int N;
    cin >> N;
    vector<int> a(N+1),b(N+1),c(N+1);
    for(int i = 1; i <= N; i++){
        cin >> a[i] >> b[i] >> c[i];
    }

    /*dp[i][j]をjをしたi日目の幸福度の最大値とする*/
    vector<vector<int>> dp(N+1, vector<int>(3,-1E8));
    dp[0][0] = dp[0][1] = dp[0][2] = 0; //0日目は何もしていない
    for(int i = 1; i <= N; i++){
        chmax(dp[i][0], max(dp[i-1][1],dp[i-1][2]) +a[i]); //aを選択。前日bかcをした日のうち、大きい方に加算
        chmax(dp[i][1], max(dp[i-1][0],dp[i-1][2]) +b[i]); //bを選択
        chmax(dp[i][2], max(dp[i-1][0],dp[i-1][1]) +c[i]); //cを選択
    }

    cout << max(dp[N][0],max(dp[N][1],dp[N][2])) << endl;
    return 0;
}