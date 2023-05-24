#include <bits/stdc++.h>
using namespace std;

template <class T>
void chmin(T &a, T b){
    if(a > b) a = b;
}

int main(){
    int N,K;
    cin >> N >> K;

    vector<int> h(N+1);
    for(int i = 1; i <= N; i++){
        cin >> h[i];
    }

    /*dp[i]を足場iにつくときのコストの最小値とする
    dp[i] = min(dp[i-1]+cost, dp[i-2]+cost.., dp[i-K]+cost)*/
    vector<int> dp(N+1,1e9);
    dp[1] = 0; //足場1はスタート地点
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= K; j++){
            if(i-j >= 0){
                chmin(dp.at(i), dp.at(i-j)+abs(h.at(i-j)-h.at(i)));
            }else{
                break;
            }
        }
    }

    cout << dp.at(N) << endl;
    return 0;
}