#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

int main(){
    ll N,K; cin >> N >> K;

    if(N==1){
        cout << 1 << endl;
        return 0;
    }

    mint ans = 1; // 黒いボールが1にある確率
    mint p1 = mint(N*N - 2*N + 2) / mint(N*N); // 移動しない
    mint p2 = mint(2) / mint(N*N); // 1に移動
    // cout << p1.val() << " " << p2.val() << endl;

    for(int i = 0; i < K; i++){
        ans = (ans * p1) + ( (1-ans) * p2);
    }

    // 2~Nにある確率は等確率なので q = (1-ans) / N-1
    // ans + (2*q + 3*q + 4*q + ...) = ans + q * { (N-1)*(2+N) / 2}
    mint q = (1-ans) / mint(N-1);
    cout << ( ans + q * mint( (N-1)*(N+2) / 2) ).val();
    return 0;
}