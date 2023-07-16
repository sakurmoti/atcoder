#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,T,M;
    cin >> N >> T >> M;

    vector<vector<int>> dislike(N);
    for(int i = 0; i < M; i++){
        int a,b;
        cin >> a >> b;
        dislike[a].push_back(b);
    }


    vector<vector<ll>> dp(N+1, vector<ll>(T+1,0));
    dp[0][0] = 1;
    cout << endl;
    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= T; j++){
            dp[i][j] = (j*dp[i-1][j] + dp[i-1][j-1]);
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    
    //dp[N][T]が相性の良しあしを気にしない時の組み分け数 -> 第二種スターリング数
    cout << dp[N][T] << endl;

    return 0;
}