#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    ll L,N,M; cin >> L >> N >> M;

    vector<pair<ll, ll>> A(N), B(M);
    for(auto &v : A) cin >> v.first >> v.second;
    for(auto &v : B) cin >> v.first >> v.second;

    ll ans = 0;
    int i = 0, j = 0;
    ll x = 0, y = 0;
    while(i < N && j < M){
        auto[u, n] = A[i];
        auto[v, m] = B[j];

        auto increment = [&]() {
            if(i == N-1){
                y += m;
                j++;
            }else if(j == M-1){
                x += n;
                i++;
            }else if(x+n < y+m){
                x += n;
                i++;
            }else{
                y += m;
                j++;
            }
        };

        // 異なる場合、どちらかの端まで飛ばす
        if(u != v){
            increment();
        
        }else{
            ans += max(0LL, min(x+n, y+m) - max(x, y) );

            increment();
        }
    }

    cout << ans << endl;
    return 0;
}