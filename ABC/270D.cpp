#include <bits/stdc++.h>
using namespace std;

template <typename T>
void chmax(T &a, T b){
    if(a < b) a = b;
}

int main(){
    int N,K;
    cin >> N >> K;

    vector<int> A(K);
    for(int i = 0; i < K; i++){
        cin >> A.at(i);
    }

    /*dp[i]をi個石があるとき、先手が取れる石の数とする
    このとき、後手が取れる石の数はi-dp[i]となる。(dp[i]が先手の取れる石の数で、A1=1から必ず全ての石を取れるから)
    高橋さんがAi個の石を取ったとき、n-Ai個で青木さんに回るが、高橋さんが取れるのは、
    場にn-Ai個の石があるとき、後手が取れる石の数となる。
    ゆえに遷移式は
    dp[i] = max(dp[i], A[i] + ( (n-A[i]) - dp[n-A[i]] ))
    ただしn >= A[i]でなければならない
    */
    vector<int> dp(N+1,0);
    for(int i = 0; i <= N; i++){
        for(int j = 0; j < K; j++){
            if(i >= A.at(j)){
                chmax( dp.at(i), A.at(j)+((i-A.at(j)) - dp.at(i-A.at(j))) );
            }

        }
    }

    cout << dp[N] << endl;
    return 0;
}