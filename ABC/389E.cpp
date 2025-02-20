#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
struct Point{int x,y; Point(){}; Point(int _x, int _y):x(_x),y(_y){}};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    ll N,M; cin >> N >> M;
    vector<ll> P(N+1, 0);
    for(int i = 1; i <= N; i++){
        cin >> P[i];
    }

    // dp[i][j] := i番目までの商品をj個買った時の最小金額
    vector<vector<ll>> dp(N+1, vector<ll>(300, 9e18));
    for(int i = 0; i <= N; i++){
        dp[i][0] = 0;
    }

    for(int i = 1; i <= N; i++){
        for(int j = 0; j < 300; j++){
            for(int k = 0; k < 300-j; k++){
                
            }
        }
    }
    
    return 0;
}