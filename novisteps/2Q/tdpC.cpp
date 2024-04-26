#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int K; cin >> K;
    int N = pow(2,K);
    vector<int> R(N);
    for(int i = 0; i < N; i++){
        cin >> R[i];
    }

    auto EloRate = [&](int p, int q) -> double {
        return 1.0 / (1.0 + pow(10, (R[q]-R[p])/400.0 ));
    };

    // dp[i][k] := 人iがkラウンド目を勝つ確率
    vector<vector<double>> dp(N, vector<double>(K+1, 0.0));
    for(int i = 0; i < N; i++){
        dp[i][0] = 1.0;
    }

    for(int k = 1; k <= K; k++){
        int m = pow(2,k);
        for(int i = 0; i < N; i++){
            vector<int> vs;
            for(int j = 0; j < m; j++){
                int idx = m*(i/m) + j;
                vs.push_back(idx);
            }

            int mid = vs[m/2];
            // cerr << i << " : ";
            if(i >= mid){
                // 前半
                for(int j = 0; j < m/2; j++){
                    // cerr << vs[j] << " ";
                    dp[i][k] += dp[i][k-1] * dp[vs[j]][k-1] * EloRate(i, vs[j]);
                }
            }else{
                // 後半
                for(int j = m/2; j < m; j++){
                    // cerr << vs[j] << " ";
                    dp[i][k] += dp[i][k-1] * dp[vs[j]][k-1] * EloRate(i, vs[j]);
                }
            }
            // cerr << endl;
        }
    }

    for(int i = 0; i < N; i++){
        cout << fixed << setprecision(10) << dp[i][K] << endl;
    }
    return 0;
}