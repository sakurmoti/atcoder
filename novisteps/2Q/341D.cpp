#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    ll N,M,K; cin >> N >> M >> K;

    ll L = lcm(N,M);

    ll ok = 9e18;
    ll ng = 0;

    while(abs(ok-ng) >= 2){
        ll mid = (ok+ng)/2;
        // cout << mid << endl;

        ll x = (mid/N) + (mid/M) - 2*(mid/L);

        if(x >= K){
            ok = mid;
        }else{
            ng = mid;
        }
    }

    cout << ok << endl;
    return 0;
}