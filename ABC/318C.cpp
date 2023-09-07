#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N,D,P;
    cin >> N >> D >> P;
    vector<ll> F(N);
    for(auto &_v : F) cin >> _v;

    sort(F.rbegin(), F.rend());

    ll ans = 0;
    int idx = 0;
    while(true){
        ll sum = 0;
        for(int d = 0; d < D; d++){
            if(idx+d >= N){
                break;
            }
            sum += F.at(idx + d);
        }

        if(sum >= P){
            //パスを買った方がよい
            for(int d = 0; d < D; d++){
                if(idx+d >= N) break;
                F[idx + d] = 0;
            }
            ans += P;
            idx += D;

        }else{
            break;
        }
    }

    // for(auto &_v : F) cout << _v << ' ';

    for(int i = 0; i < N; i++){
        ans += F[i];
    }
    cout << ans << endl;
    return 0;
}