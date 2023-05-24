#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> A(N+1,1e9), B(N+1,1e9);
    for(int i = 2; i <= N; i++) cin >> A.at(i);
    for(int i = 3; i <= N; i++) cin >> B.at(i);

    //dp[i]を部屋iに行くまでの最短時間とする
    vector<int> dp(N+1, 0);
    dp[1] = 0; //部屋1から1の時間は0
    dp[2] = A[2]; //部屋2に行くにはA[2]の通路を通るしかない
    for(int i = 3; i <= N; i++){
        dp[i] = min(dp[i-1] + A[i], dp[i-2] + B[i]);
    }

    cout << dp[N] << endl;
    return 0;
}