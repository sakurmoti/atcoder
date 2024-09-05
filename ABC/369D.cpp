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
    vector<ll> A(N);
    for(auto &_v : A) cin >> _v;

    // dp[i][k] := kは偶奇を表す。i番目まで倒したときに得られる経験値
    vector<vector<ll>> dp(N+1, vector<ll>(2, 0));
    dp[0][0] = -1e18;
    for(int i = 1; i <= N; i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + A[i-1]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] + 2*A[i-1]);
    }

    cout << max(dp[N][0], dp[N][1]) << endl;
    return 0;
}