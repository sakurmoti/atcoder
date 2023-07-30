#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

int main(){
    string S; cin >> S;
    int N = S.size();

    /*
    文字列Sが括弧列になるには
    ・Nが偶数
    ・任意のiについてi文字目までに含まれる左括弧の数は右括弧の数以上
    ・Sに含まれる左括弧と右括弧の数は等しい
    の3つが必要十分条件
    */

    if(N%2 != 0){
        cout << 0 << endl;
        return 0;
    }

    //dp[i][j]をi文字目まで見たとき、左括弧が右括弧よりj個多いときの置き方とする
    vector<vector<mint>> dp(N+1, vector<mint>(N+1, 0));
    dp[0][0] = 1;
    for(int i = 0; i < N; i++){
        char c = S[i];
        for(int j = 0; j < N; j++){
            if(c == '('){
                dp[i+1][j+1] += dp[i][j];
            }
            if(c == ')'){
                if(j!=0) dp[i+1][j-1] += dp[i][j];
            }
            if(c == '?'){
                dp[i+1][j+1] += dp[i][j];
                if(j!=0) dp[i+1][j-1] += dp[i][j];
            }

        }
    }

    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            cout << dp[i][j].val() << " \n"[j==N];
        }
    }

    cout << dp[N][0].val() << endl;
    return 0;
}