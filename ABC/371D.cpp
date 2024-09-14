#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
struct Point{int x, y;};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N; cin >> N;
    vector<ll> X(N), P(N);
    for(auto &_v : X) cin >> _v;
    for(auto &_v : P) cin >> _v;

    vector<ll> csum(N+1,0);
    for(int i = 0; i < N; i++){
        csum[i+1] = csum[i] + P[i];
    }

    int Q; cin >> Q;
    while(Q--){
        int L,R; cin >> L >> R;

        int li = lower_bound(ALL(X), L) - X.begin();
        int ri = upper_bound(ALL(X), R) - X.begin();

        // cout << " :";
        cout << csum[ri] - csum[li] << endl;

    }
    return 0;
}