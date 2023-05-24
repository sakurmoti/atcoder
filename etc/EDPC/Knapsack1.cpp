#include<bits/stdc++.h>
using namespace std;

template<class T>
void chmax(T &a, T b){
    if(a < b) a = b;
}

int main(){
    int N,W;
    cin >> N >> W;
    vector<int> w(N+1),v(N+1); 
    for(int i = 1; i <= N; i++){
        cin >> w[i] >> v[i];
    }

    /*dp[i][j]を品物iまでのうち、重さの総和がj以下で取れる価値の最大値とする
    このとき、dp[i+1][j]はi+1を取らないときdp[i][j]
    i+1を取るときdp[i][j-w[i+1]] + v[i+1]より
    dp[i+1][j] = max(dp[i][j], dp[i][j-w[i+1]] + v[i+1])
    */
    vector<vector<long long>> dp(N+1, vector<long long>(W+1));
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= W; j++){
            if(i==0) dp.at(i).at(j) = 0; //初期化
            
            if(j-w.at(i+1) >= 0){
                dp.at(i+1).at(j)
                = max(dp.at(i).at(j), dp.at(i).at(j-w.at(i+1)) + v.at(i+1));
            
            }else{
                dp.at(i+1).at(j) = dp.at(i).at(j);

            }

        }
    }

    cout << dp.at(N).at(W) << endl;

    return 0;
}