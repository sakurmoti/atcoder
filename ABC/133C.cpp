#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll L,R;
    cin >> L >> R;

    const int MOD = 2019;

    ll ans = 1e18;
    for(ll i = L; i < R; i++){
        for(ll j = i+1; j <= R; j++){
            ans = min(ans, (i*j)%MOD);
            if(ans == 0){
                cout << 0 << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}