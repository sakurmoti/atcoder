#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> h(N+1);
    for(int i = 1; i <= N; i++) cin >> h[i];

    vector<int> dp(N+1, 0);
    dp[1] = 0;
    dp[2] = abs(h[1] - h[2]);
    for(int i = 3; i <= N; i++){
        dp[i] = min(dp[i-1] + abs(h[i-1] - h[i]), dp[i-2] + abs(h[i-2] - h[i]));
    }

    //ここまではB16と全く同じ
    //ここからdpの復元をする
    int now = N;
    vector<int> ans;
    ans.push_back(N);
    while(now > 1){
        if(now >= 2 && dp[now] == dp[now-1] + abs(h[now-1] - h[now])){
            now -= 1;

        }else if(now >= 3 && dp[now] == dp[now-2] + abs(h[now-2] - h[now])){
            now -= 2;

        }

        ans.push_back(now);
    }

    reverse(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for(auto v : ans){
        cout << v << " ";
    }
    return 0;
}