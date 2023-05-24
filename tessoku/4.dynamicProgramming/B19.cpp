#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,W;
    cin >> N >> W;

    vector<int> w(N+1),v(N+1);
    for(int i = 1; i <= N; i++){
        cin >> w.at(i) >> v.at(i);
    }

    //dp[i][j]をi番目までの品物を選び、価値jにした時の最小の重さとする
    //jは価値の最大値v_max=1000と品物N_max=100の積
    vector<vector<long long>> dp(N+1, vector<long long>(100*1000 + 1, 1e10));
    
    //初期化。i番目までの選んで価値0にするのは何も選ばない時
    for(int i = 0; i <= N; i++) dp.at(i).at(0) = 0;

    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= 100*1000; j++){
            if(j-v.at(i) >= 0){
                //i番目を選んで価値jにできるとき
                dp.at(i).at(j) = min(dp.at(i-1).at(j-v.at(i)) + w.at(i), dp.at(i-1).at(j));
            
            }else{
                //できないとき(i番目の品物を選ばない)
                dp.at(i).at(j) = dp.at(i-1).at(j);

            }
        }
    }
    
    int ans;
    for(int j = 0; j <= 100*1000; j++){
        if(dp.at(N).at(j) <= W){
            ans = j;
        }
    }

    cout << ans << endl;
    return 0;
}