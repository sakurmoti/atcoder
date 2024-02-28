#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    ll N,M,K; cin >> N >> M >> K;

    // 「NとMのうちちょうど一方のみで割り切れる数」がK個以上あるかどうか
    ll ok = 9e18;
    ll ng = 0;
    while(abs(ok-ng) >= 2){
        ll mid = (ok+ng)/2;

        /*
        Nで割り切れるのは mid/N 個
        Mで割り切れるのは mid/M 個
        NとMの両方で割り切れるのは mid/lcm(N,M) 個

        あとは包除原理
        */
        ll n = mid/N;
        ll m = mid/M;
        ll nm = mid/lcm(N,M);

        // printf("n=%lld, m=%lld, nm=%lld\n",lcm(N,M), n,m,nm);

        ll cnt = n + m - 2*nm;
        if(cnt >= K){
            ok = mid;
        }else{
            ng = mid;
        }
    }

    cout << ok << endl;
    return 0;
}