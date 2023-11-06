#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

int main(){
    int N; cin >> N;
    vector<int> A(N+1);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }

    // dp[i] := 出た目がxのとき、それ以降で何円もらえるかの平均
    vector<mint> dp(N+1, 0);
    mint p = mint(1)/mint(N);
    mint sum = A[N];
    dp[N] = A[N]; //出た目がNなら終わるしかない
    for(int i = N-1; i >= 0; i--){
        dp[i] = A[i] + sum*p;
        sum += dp[i];
    }

    cout << dp[0].val() << endl;
    return 0;
}