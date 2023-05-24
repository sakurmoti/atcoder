#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> A(N),B(N);
    for(int i = 1; i <= N-1; i++) cin >> A[i];
    for(int i = 1; i <= N-1; i++) cin >> B[i];

    vector<long long> dp(N+1, -1e5);
    dp.at(1) = 0;
    for(int i = 1; i <= N-1; i++){
        dp.at(A.at(i)) = max(dp.at(A.at(i)), dp.at(i) + 100);
        dp.at(B.at(i)) = max(dp.at(B.at(i)), dp.at(i) + 150);

        //cout << dp[i] << endl;
    }

    cout << dp.at(N) << endl;
    return 0;
}