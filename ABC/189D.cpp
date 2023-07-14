#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    vector<string> S(N+1);
    for(int i = 1; i <= N; i++){
        cin >> S[i];
    }

    /*
    f(x)をxまで見たときの答えとすると、求める答えはf(N)
    S[N]がandなら、y[i-1]とx[i]は共にtrueなので f(N) = f(N-1)
    S[N]がorなら、y[i-1]かx[i]がtrueなら良いので f(N) = 2^N + f(N-1) //2^N はy[i-1]が何でもよいとき、　f(N-1)はy[i]がtrue確定のとき
    以降、漸化式で解けばよい
    */
    vector<ll> dp(N+10, 0);
    dp[1] = 1;
    for(int i = 1; i <= N; i++){
        if(S[i] == "AND"){
            dp[i+1] = dp[i];

        }else if(S[i] == "OR"){
            dp[i+1] = pow(2,i) + dp[i];

        }
    }
    cout << dp[N+1] << endl;
    return 0;
}