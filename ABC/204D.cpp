#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    vector<int> T(N+1);
    for(int i = 1; i <= N; i++){
        cin >> T[i];
    }
    
    //2つのオーブンの使用時間のうち、長い方が最短の時間
    //2つの総和をなるべく平均的に割りたい
    int sum = 0;
    for(int i = 1; i <= N; i++){
        sum += T[i];
    }

    int avg = (sum+1)/2; //切り上げ
    const int M = 1e5;
    //dp[i][k]をi番目まで見たときの和をkにできるかとする
    vector<vector<bool>> dp(N+1, vector<bool>(M, false));
    for(int i = 0; i <= N; i++){
        dp[i][0] = true;
    }

    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= M; j++){
            if(j-T[i] >= 0 && dp[i-1][j-T[i]]){
                dp[i][j] = true; //選ぶ場合
                dp[i][j-T[i]] = true; //選ばない場合
            }
        }
    }

    // for(int i = 0; i <= N; i++){
    //     for(int j = 0; j <= M; j++){
    //         cout << dp[i][j];
    //     }
    //     cout << endl;
    // }

    

    int ans = 0;
    for(int i = 0; i <= 1e5; i++){
        int tp = avg + i;

        if(tp < 1e5 && dp[N][tp]){
            ans = tp;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}