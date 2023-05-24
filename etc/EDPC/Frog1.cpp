/*https://atcoder.jp/contests/dp*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> h(N+1);
    for(int i = 1; i <= N; i++) cin >> h[i];

    /*dp[i] = 足場iに移動したときの最小コスト
    dp漸化式は
    dp[i] = min(dp[i-1]+cost, dp[i-2]+cost)*/
    vector<int> dp(N+1,0);
    for(int i = 2; i <= N; i++){
        if(i-2 != 0){
            dp.at(i)
                = min(dp.at(i-1)+abs(h.at(i)-h.at(i-1)), dp.at(i-2)+abs(h.at(i)-h.at(i-2)));
        }else{
            dp.at(i)
                = dp.at(i-1)+abs(h.at(i)-h.at(i-1));
        }
    }

    cout << dp.at(N) << endl;

}