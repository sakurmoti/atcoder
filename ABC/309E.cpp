#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M;
    cin >> N >> M;

    vector<int> p(N+1,0);
    for(int i = 2; i <= N; i++){
        cin >> p[i];
    }

    vector<int> dp(N+1, -1);
    for(int i = 0; i < M; i++){
        int x,y; cin >> x >> y;
        //最大値の保険だけ見ればよい
        dp[x] = max(dp[x], y);
    }

    int cnt=0;
    for(int i = 1; i <= N; i++){
        //本人の保険か、親からの引継ぎか長い方
        //1の親は0としている
        dp[i] = max(dp[i], dp[p[i]]-1);
        if(dp[i] >= 0) cnt++;
    }

    // for(auto &v : dp) cout << v << ' ';
    cout << cnt << endl;
    
    return 0;
}