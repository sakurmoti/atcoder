#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    ll D; cin >> D;
    
    ll ans = 1e15;
    // 対称性からx <= yとする
    for(ll x = 0; x*x <= D; x++){
        ll x2 = x*x;
        
        ll y2 = D-x2;
        if(x2 > y2) continue;
        
        ll Y = sqrt(y2);
        for(int d = -100; d <= 100; d++){
            ll y = Y+d;
            if(y < 0 || x > y){
                continue;
            }

            y2 = y*y;
            ans = min(ans, abs(x2 + y2 - D));
        }
    }
    cout << ans << endl;
    return 0;
}