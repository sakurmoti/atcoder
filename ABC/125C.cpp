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
S op(S a, S b){return gcd(a,b);}
S e(){return 0;}

int main(){
    int N; cin >> N;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    // 1個選んでN-1個のうちのどれかにしても最適のまま
    segtree<S,op,e> seg(A);
    int ans = -1;
    for(int i = 0; i < N; i++){
        S L = seg.prod(0, i);
        S R = seg.prod(i+1, N);

        chmax(ans, gcd(L,R));
    }

    cout << ans << endl;
    return 0;
}