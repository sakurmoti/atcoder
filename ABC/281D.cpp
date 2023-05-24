//写経

#include <bits/stdc++.h>
using namespace std;

template <typename T>
void chmax(T &a, T b){
    if(a < b) a = b;
}

int main(){
    int N,K,D;
    cin >> N >> K >> D;

    vector<int> a(N);
    for(int i = 0; i < N; i++) cin >> a.at(i);

    //dp[i][j][k]とする
    //i+1番目まで見たときにj個選んで、mod Dがkであるような総和の最大値
    //初期値は-1

    vector<vector<vector<long long>>> dp(N+1, vector<vector<long long>>(K+1, vector<long long>(D, -1)));
    dp[0][0][0] = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j <= K; j++){
            for(int k = 0; k < D; k++){
                //dp[i][j][k]が-1なら存在していない
                if(dp.at(i).at(j).at(k) == -1) continue;

                //a[i]を選ばない場合
                //dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k])
                chmax(dp.at(i+1).at(j).at(k), dp.at(i).at(j).at(k));

                //a[i]を選ぶ場合
                //jがK個になっていないか注意
                //dp[i+1][j+1][(k+a[i])%D] = max(dp[i+1][j+1][(k+a[i])%D], dp[i][j][k]+a[i])
                if(j != K){
                    chmax(dp.at(i+1).at(j+1).at((k+a.at(i))%D), dp.at(i).at(j).at(k) + a.at(i));
                }

            }
        }
    }

    //答えはN番目まで見てK個選んだうち、mod  Dが0の最大値
    cout << dp.at(N).at(K).at(0) << endl;


    return 0;
}