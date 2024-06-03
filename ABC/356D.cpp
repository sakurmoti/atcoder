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
    ll N,M; cin >> N >> M;

    for(int i = 0; i <= N; i++){
        bitset<16> a(i);
        cout << a << endl;
    }
    
    bitset<64> A(M);
    mint ans(0);
    for(int i = 0; i < 64; i++){
        if(A.test(i)){
            ll width = (1LL<<(i+1));
            ll buf = ((N+1)/width);
            mint cnt(0);
            cnt += (1LL<<i)*buf;
            // cout << cnt.val() << " ";

            ll modulo = (N+1)%width;
            cnt += max(0LL, modulo - (width/2));
            // cout << cnt.val() << endl;

            ans += cnt;
        }
    }

    cout << ans.val() << endl;
    return 0;
}