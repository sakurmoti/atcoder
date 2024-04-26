#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    ll N,M,P;
    cin >> N >> M >> P;

    vector<ll> A(N),B(M);
    for(auto &_v : A) cin >> _v;
    for(auto &_v : B) cin >> _v;

    sort(ALL(B));
    vector<ll> csumB(M+1,0);
    for(int i = 1; i <= M; i++){
        csumB[i] = csumB[i-1] + B[i-1];
    }

    ll ans = 0;
    for(int i = 0; i < N; i++){
        if(A[i] + B[0] >= P){
            ans += M*P;
            continue;
        }
        
        ll ok = 0;
        ll ng = M;
        while(abs(ok-ng) >= 2){
            ll mid = (ok+ng)/2;

            if(A[i]+B[mid] < P){
                ok = mid;
            }else{
                ng = mid;
            }
        }

        // printf("ok=%lld, ng=%lld\n",ok,ng);
        ans += A[i]*(ok+1) + csumB[ok+1] + (M-ng)*P;
        // cout << ans << endl;
    }

    cout << ans << endl;
    return 0;
}