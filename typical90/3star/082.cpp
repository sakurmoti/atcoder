#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;

int main(){
    ll L,R; cin >> L >> R;
    
    ull l = 1;
    ull r = 10;
    mint ans(0);
    for(int keta = 1; keta <= 19; keta++){
        ull vl = max((ull)L, l);
        ull vr = min((ull)R, r-1);
        
        l *=10;
        r *=10;
        if(vl > vr){
            continue;
        }

        mint sum_l = mint(vl-1) * mint(vl) * mint(2).inv();
        mint sum_r = mint(vr) * mint(1+vr) * mint(2).inv();
        ans += mint(keta) * (sum_r - sum_l);
    }

    cout << ans.val() << endl;
    return 0;
}