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
S op(S a, S b){return (a+b);}
S e(){return 0;}

int main(){
    int N; cin >> N;
    vector<int> A(2*N);
    for(int i = 0; i < N; i++){
        int l,r;
        cin >> l >> r;

        A[2*i] = l;
        A[2*i+1] = r;
    }

    auto cp = A;
    sort(ALL(cp));
    cp.erase(unique(ALL(cp)), cp.end());
    
    vector<int> zatu(2*N);
    for(int i = 0; i < 2*N; i++){
        zatu[i] = lower_bound(ALL(cp), A[i]) - cp.begin();
    }

    // for(auto v : zatu) cout << v << " "; cout << endl;

    vector<pair<int, int>> event(N);
    for(int i = 0; i < N; i++){
        event[i] = make_pair(zatu[2*i], zatu[2*i+1]);
    }

    sort(ALL(event), [](auto a, auto b){return a.second < b.second;});
    // for(auto [l,r] : event){cout << l << " " << r << endl;} cout << endl;

    segtree<S, op, e> seg(zatu.size());
    ll ans = 0;

    for(auto [l,r] : event){
        ans += seg.prod(l,r+1); // [r[1], r[j-1]]のうちl[j]以上の個数
        seg.set(r, seg.get(r)+1);
    }

    cout << ans << endl;
    return 0;
}