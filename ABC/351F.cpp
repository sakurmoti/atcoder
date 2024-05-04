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
using S = ll;
S op(S a, S b){return a+b;}
S e(){return 0;}

int main(){
    int N; cin >> N;
    vector<ll> A(N);
    for(auto &_v : A) cin >> _v;

    // AそのままだとA[i] <= 1e8で厳しいので座圧をかける
    auto B = A;
    vector<int> zatu(N);
    sort(ALL(B));
    B.erase(unique(ALL(B)), B.end());
    // for(auto &_v : B) cout << _v << " "; cout << endl;
    for(int i = 0; i < N; i++){
        int idx = lower_bound(ALL(B), A[i]) - B.begin();
        zatu[i] = idx;
    }

    // for(auto &_v : zatu) cout << _v << " "; cout << endl;

    // 平面走査
    ll ans = 0;
    int M = B.size();
    segtree<S,op,e> seg1(M),seg2(M);
    for(int i = N-1; i >= 0; i--){
        auto x = zatu[i];

        S c = seg1.prod(x, M);
        S s = seg2.prod(x, M);
        // cout << "c : " << c << " s : " << s << endl;

        ans += (s - c*A[i]);

        seg1.set(x, seg1.get(x) + 1);
        seg2.set(x, seg2.get(x) + A[i]);
    }

    // fenwick_tree<ll> fw1(N),fw2(N);
    // ll ans = 0;
    // for(int i = N-1; i >= 0; i--){
    //     auto x = zatu[i];

    //     S c = fw1.sum(x, N);
    //     S s = fw2.sum(x, N);
    //     cout << "c : " << c << " s : " << s << endl;

    //     ans += (s - c*x);

    //     fw1.add(x, 1);
    //     fw2.add(x, A[i]);
    // }

    cout << ans << endl;
    return 0;
}