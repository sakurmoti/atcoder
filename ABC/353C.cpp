#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    ll N; cin >> N;
    vector<ll> A(N);
    for(auto &_v : A) cin >> _v;

    sort(ALL(A)); // 組合せなのでソートしても良い
    // for(auto &_v : A) cout << _v << " "; cout << endl;

    constexpr ll MOD = 1e8;
    vector<ll> lim(N); // 和が1e8を超える直前のidx
    for(int i = 0; i < N; i++){
        if(A[i] + A[0] >= MOD){
            lim[i] = 0;
            continue;
        }

        int ok = i;
        int ng = N;
        while(abs(ok - ng) >= 2){
            int mid = (ok + ng)/2;

            if(A[i] + A[mid] >= MOD){
                ng = mid;
            }else{
                ok = mid;
            }
        }

        lim[i] = ok+1;
    }

    // for(auto &_v : lim) cout << _v << " "; cout << endl;

    ll ans = 0;
    ll minus = 0;
    for(int i = 0; i < N; i++){
        ll sum = (A[i] * (N-1));
        // cerr << sum << " ";
        ans += sum;

        minus += min(N-i-1, N-lim[i]) * MOD;
        // cerr << minus << endl;
    }

    cout << ans-minus << endl;
    return 0;
}