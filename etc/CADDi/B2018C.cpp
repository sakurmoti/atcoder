// https://atcoder.jp/contests/caddi2018b/tasks/caddi2018_a

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N,P;
    cin >> N >> P;

    //Pを素因数分解して、N個あるものが最大公約数の要素になりうる
    map<ll, ll> factor;
    for(ll i = 2; i*i <= P; i++){
        if(P%i == 0){
            ll cnt = 0;
            while(P%i == 0){
                cnt++;
                P /= i;
            }
            factor[i] = cnt;
        }
    }
    factor[P] = 1; //最後の素数(割り切れたならP=1になっている)

    ll ans = 1;
    for(auto v : factor){
        // printf("%d : %d\n",v.first,v.second);
        if(v.second >= N){
            ans *= (ll)pow(v.first, (v.second/N));
        }
    }
    cout << ans << endl;
    return 0;
}