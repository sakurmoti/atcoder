#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;
    
    vector<ll> dp(N, 0);
    for(int i = 1; i < N; i++){
        dp[i] = dp[i-1] + abs(A[i]-A[i-1]);
        if(i>=2) dp[i] = min(dp[i], dp[i-2] + abs(A[i]-A[i-2]));
    }

    cout << dp[N-1] << endl;
    return 0;
}