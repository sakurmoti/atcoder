#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,K; cin >> N >> K;
    deque<ll> P{0},M;
    vector<int> buf;
    for(int i = 0; i < N; i++){
        ll x; cin >> x;
        if(x>0){
            P.push_back(x);
        }else{
            M.push_front(abs(x));
        }
    }
    M.push_front(0);

    // for(int _i = 0; _i < P.size(); _i++) cout << P[_i] << " \n"[_i == P.size()-1];
    // for(int _i = 0; _i < M.size(); _i++) cout << M[_i] << " \n"[_i == M.size()-1];

    ll ans = 1e18;
    for(int i = 0; i < P.size(); i++){
        if(i > K) break;
        ll p = P[i]; // 正のろうそくを付ける時間
        
        if(K-i >= M.size()) continue;
        ll m = M[K-i];

        ans = min(ans, p+m + min(p,m)); // 往復含めた時間
    }

    cout << ans << endl;
    return 0;
}