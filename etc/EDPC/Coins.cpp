#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<double> p(N+1);
    for(int i = 1; i <= N; i++){
        cin >> p.at(i);
    }

    /*dp[i]をi枚目まで投げたときに表の方が多い確率だと次に遷移するのが裏だとだめなのかわからない
    そこでdp[i][j]をi枚目まで投げたときにj枚表の確率とする。(遷移式が書けないなら情報を増やす!)
    
    dp[i][j] = (dp[i-1][j-1] * p[i]) + (dp[i-1][j] * (1-p[i]))となる*/

    vector<vector<double>> dp(N+1, vector<double>(N+1,0));
    dp.at(1).at(0) = 1- p.at(1);
    dp.at(1).at(1) = p.at(1);

    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= i; j++){
            dp.at(i).at(j) = dp.at(i-1).at(j) * (1- p.at(i));
            if(j > 0) dp.at(i).at(j) += dp.at(i-1).at(j-1) * p.at(i);

        }
    }

    /*for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            printf("dp[%d][%d] = %lf\n",i,j, dp[i][j]);
        }
    }*/

    double ans=0;
    for(int j = N/2 +1; j <= N; j++){
        ans += dp[N][j];
    }

    cout << ans << endl;

    return 0;
}