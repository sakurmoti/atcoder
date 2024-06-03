#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N,Q; cin >> N >> Q;
    vector<ll> A(N+1, 0);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }

    ll ans = 0;
    vector<ll> diff(N+1, 0);
    for(int i = 1; i < N; i++){
        diff[i] = A[i] - A[i+1];
        ans += abs(diff[i]);
    }

    while(Q--){
        int L,R,V; cin >> L >> R >> V;

        ll prev = abs(diff[L-1]) + abs(diff[R]);

        if(L!=1) diff[L-1] -= V;
        if(R!=N) diff[R] += V;

        ll next = abs(diff[L-1]) + abs(diff[R]);

        ans += (next - prev);
        cout << ans << endl;
    }
    return 0;
}