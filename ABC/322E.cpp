#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,K,P;
    cin >> N >> K >> P;

    int M = P+1;
    ll dp[M][M][M][M][M];
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            for(int k = 0; k < M; k++){
                for(int l = 0; l < M; l++){
                    for(int m = 0; m < M; m++){
                        dp[i][j][k][l][m] = 1e15;
                    }
                }
            }
        }
    }

    dp[0][0][0][0][0] = 0;

    vector<ll> C(N);
    vector<vector<int>> A(N,vector<int>(5));
    for(int i = 0; i < N; i++){
        cin >> C[i];
        for(int j = 0; j < 5; j++){
            if(j < K){
                cin >> A[i][j];
            }else{
                A[i][j] = P;
            }
        }
    }

    for(int o = 0; o < N; o++){
        for(int i = P; i >= 0; i--){
            for(int j = P; j >= 0; j--){
                for(int k = P; k >= 0; k--){
                    for(int l = P; l >= 0; l--){
                        for(int m = P; m >= 0; m--){
                            int i2 = min(P,i+A[o][0]);
                            int j2 = min(P,j+A[o][1]);
                            int k2 = min(P,k+A[o][2]);
                            int l2 = min(P,l+A[o][3]);
                            int m2 = min(P,m+A[o][4]);

                            dp[i2][j2][k2][l2][m2] = min(dp[i2][j2][k2][l2][m2], dp[i][j][k][l][m] + C[o]);

                        }
                    }
                }
            }
        }
    }

    // int cnt = 0;
    // for(int i = 0; i < M; i++){
    //     for(int j = 0; j < M; j++){
    //         for(int k = 0; k < M; k++){
    //             for(int l = 0; l < M; l++){
    //                 for(int m = 0; m < M; m++){
    //                     if(dp[i][j][k][l][m] > 1e9) continue;
    //                     cnt++;
    //                     printf("dp[%d][%d][%d][%d][%d] = %lld\n", i,j,k,l,m,dp[i][j][k][l][m]);
    //                 }
    //             }
    //         }
    //     }
    // }
    // cout << cnt << endl;

    
    ll ans = dp[P][P][P][P][P];
    if(ans >= 1e14) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}