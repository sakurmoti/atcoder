#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    vector<ll> Q(N),A(N),B(N);
    for(auto &_v : Q) cin >> _v;
    for(auto &_v : A) cin >> _v;
    for(auto &_v : B) cin >> _v;

    // 料理Aをi人作るとき
    ll ans = 0;
    for(ll i = 0; i <= 1'000'000; i++){
        bool flag = true;
        for(int j = 0; j < N; j++){
            if(Q[j] - A[j]*i < 0) flag = false;
        }
        if(!flag) break;

        ll bMin = 1e9;
        for(int j = 0; j < N; j++){
            int q = Q[j] - (A[j] * i);
            if(B[j] == 0) continue;
            bMin = min(bMin, q/B[j]);
        }

        if(bMin < 0) break;

        ans = max(ans , i + bMin);
        // fprintf(stderr, "i=%d, bMax=%d\n", i,bMin);
    }
    cout << ans << endl;
    return 0;
}