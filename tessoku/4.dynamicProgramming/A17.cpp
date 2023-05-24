#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> A(N+1), B(N+1);
    for(int i = 2; i <= N; i++) cin >> A[i];
    for(int i = 3; i <= N; i++) cin >> B[i];

    //まずはdpで最短ルートを探す
    vector<int> dp(N+1, 1e9);
    dp[1] = 0;
    dp[2] = A[2];
    for(int i = 3; i <= N; i++){
        dp[i] = min(dp[i-1] + A[i], dp[i-2] + B[i]);
    }

    //dpによって部屋Nまでの最短時間がわかった
    //もし最短経路で来ているならdp[i] = dp[i-1]+A[i]、またはdp[i-2]+B[i]が成立する
    //この成立する方に逆にたどっていく
    int now = N;
    vector<int> route;
    route.push_back(N);
    while(now > 1){
        if(now > 1 && dp[now] == dp[now-1] + A[now]){
            route.push_back(now-1);
            now -= 1;
        
        }else if(now > 2 && dp[now] == dp[now-2] + B[now]){
            route.push_back(now-2);
            now -= 2;

        }
    }

    reverse(route.begin(), route.end());

    cout << route.size() << endl;
    for(auto v : route){
        cout << v << " ";
    }
    
    return 0;
}