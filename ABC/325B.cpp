#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    vector<int> W(N),X(N);
    for(int i = 0; i < N; i++){
        cin >> W[i] >> X[i];
    }

    ll ans = -1;
    for(int t = 0; t <= 24; t++){
        ll cnt = 0;
        for(int i = 0; i < N; i++){
            int x = X[i] + t;
            x %= 24;
            if(9 <= x && x <= 17){
                cnt += W[i];
            }
        }

        ans = max(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}