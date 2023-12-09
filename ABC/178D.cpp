#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;

int main(){
    int S; cin >> S;

    // dp[i] := 総和がiになるような数列の個数
    vector<mint> dp(S+1, 0);
    dp[0] = 1;
    mint sum = 1;

    for(int i = 1; i <= S; i++){
        // 総和がjになるような数列に、総和がiになるように項を追加
        // ある項に加算すると重複してしまう
        mint T = sum;
        if(i-1 >= 0) T -= dp[i-1];
        if(i-2 >= 0) T -= dp[i-2];

        dp[i] = T;
        sum += dp[i];
    }

    cout << dp[S].val() << endl;
    return 0;
}