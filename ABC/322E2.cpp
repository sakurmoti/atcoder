#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,K,P;
    cin >> N >> K >> P;
    
    vector<int> C(N+1);
    vector<vector<int>> A(N+1, vector<int>(K));
    for(int i = 1; i <= N; i++){
        cin >> C[i];
        for(int j = 0; j < K; j++){
            cin >> A[i][j];
        }
    }

    // 状態はP以上をPと扱っても同じなので、K個のパラメータに対しての0~Pの(P+1)^K通り
    // dp[i][S] := i個目の開発案まで見たとき、状態がSになるコストの最小値
    map<pair<int,vector<int>>, ll> dp;
    for(int i = 1; i <= N; i++){
        vector<int> S(K);
        for(int j = 1; j <= (int)pow(P+1, K); j++){
            int j2 = j;
            for(int k = 0; k < K; k++){
                S[k] = j2%(P+1);
                j2 /= P;
            }

            dp[make_pair(i, S)] = 1e18;
        }
    }

    for(int i = 1; i <= N; i++){
        vector<int> S(K);
        for(int j = 0; j <= (int)pow(P+1, K); j++){
            int j2 = j;
            for(int k = 0; k < K; k++){
                S[k] = j2%(P+1);
                j2 /= P;
            }

            // 開発案を実行しない
            dp[make_pair(i, S)] = min(dp[make_pair(i,S)], dp[make_pair(i-1, S)]);

            // 開発案を実行
            vector<int> T = S;
            for(int k = 0; k < K; k++) T[k] += A[i][k];
            dp[make_pair(i, T)] = min(dp[make_pair(i, T)], dp[make_pair(i-1, S)] + C[i]);
        }
    }

    ll ans = dp[make_pair(N, vector<int>(K, P))];
    cout << (ans > 1e17 ? -1 : ans) << endl;
    return 0;
}