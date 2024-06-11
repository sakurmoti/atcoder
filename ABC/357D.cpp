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
    ll N; cin >> N;
    // sigma_[0,N) 10^i *N

    int len = to_string(N).size();
    // cout << len << endl;

    mint R = mint(10).pow(len);
    mint sum10 = (R.pow(N) - mint(1)) * mint(R-1).inv();
    mint ans = mint(N) * sum10;
    cout << ans.val() << endl;
    return 0;
}