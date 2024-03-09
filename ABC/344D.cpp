#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    string T; cin >> T;
    int M = T.size();
    int N; cin >> N;

    vector<vector<string>> S(N);
    for(int i = 0; i < N; i++){
        int a; cin >> a;
        for(int j = 0; j < a; j++){
            string s; cin >> s;
            S[i].push_back(s);
        }
    }

    // dp[i][j] := i番目の袋まで見たとき、T[j]までを一致させる最小の金額
    vector<vector<int>> dp(N+1, vector<int>(M+1, 1e9));
    for(int i = 0; i <= N; i++) dp[i][0] = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
        }

        for(int j = 0; j < S[i].size(); j++){
            string s = S[i][j];
            int len = s.size();

            for(int k = 0; k+len < M; k++){
                bool flag = true;
                for(int l = 0; l < len; l++){
                    if(T[k+l] != s[l]){
                        flag = false;
                        break;
                    }
                }

                if(flag){
                    dp[i+1][k+len] = min(dp[i+1][k+len], dp[i][j]+1);
                }
            }
        }
    }

    for(auto u : dp){
        for(auto v : u){
            if(v > 1e8) cout << "00 ";
            else cout << v << "  ";
        }
        cout << endl;
    }

    if(dp[N][M] > 1e8) cout << -1 << endl;
    else cout << dp[N][M] << endl;
    return 0;
}