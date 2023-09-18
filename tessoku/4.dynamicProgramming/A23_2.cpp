#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M;
    cin >> N >> M;

    vector<vector<int>> A(M+1, vector<int>(N));
    for(int i = 1; i <= M; i++){
        for(int j = 0; j < N; j++){
            cin >> A[i][j];
        }
    }

    //Aのbit表記を整数表現に直す. 上の入力だと001の入力は100 = 4と計算されることに注意. 集合の計算にはなんら問題ない
    vector<int> B(M+1);
    for(int i = 1; i <= M; i++){
        int calc = 0;
        for(int j = 0; j < N; j++){
            calc += (A[i][j] * (1<<j) );
        }

        B[i] = calc;
        // printf("A[%d] = %d\n", i, B[i]);
    }

    //dp[i][S] := i枚目までのクーポンを見たときに、集合Sの品物が無料で買える最小のクーポン枚数
    vector<vector<int>> dp(M+1, vector<int>(1<<N, 1e5));
    for(int i = 0; i <= M; i++){
        dp[i][0] = 0;
    }

    for(int i = 1; i <= M; i++){
        for(int b = 0; b < (1<<N); b++){
            int idx = b | B[i];
            // printf("%d or %d = %d\n",b,B[i],idx);
            
            dp[i][b] = min(dp[i][b], dp[i-1][b]);
            dp[i][idx] = min(dp[i][idx], dp[i-1][b] + 1);
        }
    }

    // for(int i = 1; i <= M; i++){
    //     for(int b = 0; b < (1<<N); b++){
    //         printf("dp[%d][%d] = %d\n", i,b,dp[i][b]);
    //     }
    // }

    //答えはM枚目まで見たとき、全てのbitが立っているdp
    int ans = dp[M][(1<<N) -1];
    if(ans > 1e4) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}