#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    ll N,M; cin >> N >> M;
    vector<ll> A(N);
    for(auto &_v : A) cin >> _v;

    sort(ALL(A));

    vector<ll> csum(N+1, 0);
    for(int i = 0; i < N; i++){
        csum[i+1] = csum[i] + A[i];
    }

    if(csum[N] <= M){
        cout << "infinite" << endl;
        return 0;
    }

    ll ok = 0;
    ll ng = A[N-1];
    while(abs(ok-ng) >= 2){
        ll mid = (ok+ng)/2;

        ll idx = upper_bound(ALL(A), mid) - A.begin();
        ll p = csum[idx];
        ll m = mid * (N-idx);

        // printf("x = %lld, idx=%lld, p=%lld, m=%lld\n",mid,idx, p, m);
        if(p+m <= M){
            ok = mid;
        }else{
            ng = mid;
        }
    }

    cout << ok << endl;
    return 0;
}