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
using mint = modint1000000007;

int main(){
    int N; cin >> N;

    mint ans(1);
    for(int i = 0; i < N; i++){
        mint sum(0);
        for(int j = 0; j < 6; j++){
            int a; cin >> a;
            sum += a;
        }
        ans *= sum;
    }

    // (a1+a2+a3)(b1+b2+b3)(c1+c2+c3)のような形は展開したら総当たりと一緒なので
    cout << ans.val() << endl;
    return 0;
}