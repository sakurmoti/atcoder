#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

int main(){
    int N,M,K; cin >> N >> M >> K;

    // dp[i][j] := i番目まで決定したときの総和がjになる組み合わせ
    vector<vector<mint>> dp(N+1, vector<mint>(K+1, 0));
    dp[0][0] = 1;

    // O(NMK)解法
    // for(int i = 1; i <= N; i++){
    //     for(int j = 1; j <= K; j++){
            
    //         // A[i] = kの場合
    //         printf("j = %d\nk= ", j);
    //         for(int k = 1; k <= min(M,j); k++){
    //             printf("%d ", j-k);
    //             dp[i][j] += dp[i-1][j-k];
    //         }
    //         printf("\n");
    //     }
    // }


    // 累積和で高速化して O(NK)
    vector<vector<mint>> csum(N+1, vector<mint>(K+1, 0));
    fill(csum[0].begin() + 1, csum[0].end(), 1);
    for(int i = 1; i <= N; i++){
        for(int j = i; j <= K; j++){
            dp[i][j] = csum[i-1][j] - csum[i-1][max(0, j-M)];
            csum[i][j] = csum[i][j-1] + dp[i][j-1];

        }
    }

    // cout << "csum : \n";
    // for(auto u : csum){
    //     for(auto v : u){
    //         cout << v.val() << " ";
    //     }
    //     cout << endl;
    // }

    // cout << "dp : \n";
    // for(auto u : dp){
    //     for(auto v : u){
    //         cout << v.val() << " ";
    //     }
    //     cout << endl;
    // }

    mint ans = accumulate(dp[N].begin(), dp[N].end(), mint(0));
    cout << ans.val() << endl;
    return 0;
}