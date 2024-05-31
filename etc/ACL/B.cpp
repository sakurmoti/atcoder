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
using S = int;

int main(){
    int N,Q; cin >> N >> Q;
    
    fenwick_tree<ll> fw(N);
    for(int i = 0; i < N; i++){
        int a; cin >> a;
        fw.add(i,a);
    }

    while(Q--){
        int q; cin >> q;

        if(q == 0){
            int p,x; cin >> p >> x;
            fw.add(p, x);
        }else{
            int l,r; cin >> l >> r;
            cout << fw.sum(l,r) << endl;
        }
    }
    return 0;
}