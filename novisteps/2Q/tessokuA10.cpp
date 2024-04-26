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
S op(S a, S b){return max(a,b);}
S e(){return -1;}


int main(){
    int N; cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    segtree<S, op, e> seg(A);

    int D; cin >> D;
    while(D--){
        int L,R; cin >> L >> R;
        L--; R--;
        S left = seg.prod(0, L);
        S right = seg.prod(R+1, N);

        cout << max(left, right) << endl;
    }
    return 0;
}