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
using T = int;
S op1(S a, S b){return min(a,b);}
S e1(){return 1e9;}

T op2(T a, T b){return max(a,b);}
T e2(){return -1;}

int main(){
    int N,K; cin >> N >> K;
    vector<pair<int, int>> P(N+1);
    for(int i = 1; i <= N; i++){
        cin >> P[i].first;
        P[i].second = i;
    }

    sort(ALL(P));
    vector<int> idx(N);
    for(int i = 0; i < N; i++){
        idx[i] = P[i+1].second;
    }

    // for(auto &_v : idx) cout << _v << " "; cout << endl;

    segtree<S, op1, e1> seg1(idx);
    segtree<T, op2, e2> seg2(idx);

    int ans = 1e9;
    for(int i = 0; i <= N-K; i++){
        int m = seg1.prod(i, i+K);
        int M = seg2.prod(i, i+K);

        // cout << "[" << i << "," << i+K << ") : ";
        // cout << m << " " << M << endl;
        chmin(ans, M-m);
    }

    cout << ans << endl;
    return 0;
}