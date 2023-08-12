#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;

int main(){
    int N,W,L,R;
    cin >> N >> W >> L >> R;
    vector<int> X(N+2,0);
    for(int i = 1; i <= N; i++){
        cin >> X[i];
    }
    X[0] = 0; //西岸
    X[N+1] = W; //東岸

    vector<mint> dp(N+2, 0); //i番目の足場まで移動する方法
    vector<mint> cul_sum(N+2,0);
    dp[0] = 1;
    cul_sum[0] = 1;
    for(int i = 1; i <= N+1; i++){
        /*L以上R以下の足場を+dp[i]する
        それは遅いので累積和で実装

        L以上R以下は単調性からにぶたんで探す
        足場idxから足場iに飛べるか考えるとき、
        Rメートル以下 <-> X[idx] + R >= X[i]  <->  X[i]-R <= X[idx]
        Lメートル以上 <-> X[idx] + L <= X[i]  <->  X[i]-L >= X[idx]
        */
        
        //L <= Rの制約から X[i]-R <= X[i]-LなのでposLをX[i]-Rとする
        int posL = distance(X.begin(), lower_bound(X.begin(), X.end(), X[i] - R));
        int posR = distance(X.begin(), lower_bound(X.begin(), X.end(), X[i] - L + 1)); //X[i]-Lより1だけ大きい値の最小値を求めて
        posR--; //1引くことでX[i]-L以下の最大値を求める
        // printf("X[%d] = %d, posL = %d, posR = %d\n",i,X[i], posL, posR);

        if(posR < 0) dp[i] = 0;
        else dp[i] = cul_sum[posR];

        if(posL > 0) dp[i] -= cul_sum[posL-1];

        cul_sum[i] = cul_sum[i-1] + dp[i];
    }

    cout << dp[N+1].val() << endl;
    return 0;
}