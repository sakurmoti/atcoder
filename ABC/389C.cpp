#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
struct Point{int x,y; Point(){}; Point(int _x, int _y):x(_x),y(_y){}};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

#include <atcoder/all>
using namespace atcoder;
using S = ll;
S op(S a, S b){return a+b;}
S e(){return 0;}

int main(){
    int Q; cin >> Q;

    segtree<S, op, e> seg(1e6);
    ll l = 0;
    ll r = 0;
    while(Q--){
        int q; cin >> q;

        if(q==1){
            ll k; cin >> k;
            seg.set(r, k);
            r++;

        }else if(q==2){
            l++;

        }else{
            ll k; cin >> k;
            // cerr << "\t";
            cout << seg.prod(l, l+k-1) << endl;
        }
    }
    return 0;
}