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

int main(){
    int N,Q; cin >> N >> Q;
    dsu d(N);

    while(Q--){
        int t,u,v;
        cin >> t >> u >> v;

        if(t == 0) d.merge(u,v);
        else{
            if(d.same(u,v)) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
    return 0;
}