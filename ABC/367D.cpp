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
    int N,M; cin >> N >> M;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    for(int i = 0; i < N; i++){
        A[i] %= M;
    }

    vector<int> csum(2*N-1, 0);
    for(int i = 0; i < 2*N-2; i++){
        csum[i+1] = csum[i] + A[i%N];
        csum[i+1] %= M;
    }

    // for(auto &_v : csum) cout << _v << " "; cout << endl;

    vector<int> cnt(M, 0);
    for(int i = 1; i < N; i++){
        cnt[csum[i]]++;
    }

    ll ans = 0;
    for(int i = 0; i < N; i++){
        ans += cnt[csum[i]];

        // for(auto &_v : cnt) cout << _v << " "; cout << endl;

        if(i == N-1) break;
        cnt[csum[i+1]]--;
        cnt[csum[i+N]]++;
    }

    cout << ans << endl;
    return 0;
}