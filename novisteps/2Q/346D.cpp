#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    string S; cin >> S;
    S.insert(S.begin(), ' ');
    vector<ll> C(N+1,0);
    for(int i = 1; i <= N; i++){
        cin >> C[i];
    }

    // S[x]をyにするためのコスト
    auto cost = [&](int x, char y) {
        if(S[x] != y) return C[x];
        return 0LL; 
    };

    // dp[i][j][k] := i文字目がkであって、連続する文字がj個あるときのコスト
    vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(2,vector<ll>(2, 1e18)));
    dp[0][0][0] = 0; dp[0][0][1] = 0;

    for(int i = 1; i <= N; i++){
        dp[i][0][0] = dp[i-1][0][1] + cost(i, '0');
        
        dp[i][0][1] = dp[i-1][0][0] + cost(i, '1');

        if(i!=1){
            dp[i][1][0] = min({
                dp[i-1][1][1] + cost(i, '0'),
                dp[i-1][0][0] + cost(i, '0')
                });
            
            dp[i][1][1] = min({
                dp[i-1][1][0] + cost(i, '1'),
                dp[i-1][0][1] + cost(i, '1')
                });
        }
    }

    cout << min(dp[N][1][0], dp[N][1][1]) << endl;

    return 0;
}