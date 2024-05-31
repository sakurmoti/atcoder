#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N,M; cin >> N >> M;
    vector<ll> X(N+1, 0);
    for(int i = 1; i <= N; i++){
        cin >> X[i];
    }

    vector<ll> bonus(N+1, 0);
    for(int i = 0; i < M; i++){
        int k,v; cin >> k >> v;
        bonus[k] = v;
    }

    vector<vector<ll>> dp(N+1, vector<ll>(N+1, 0));
    ll Maxi = 0; // 現在のコイントスの最大値
    for(int i = 0; i < N; i++){
        // printf("%d kaime  : %lld\n",i, Maxi);
        chmax(dp[i+1][0], Maxi); //裏の場合
        
        for(int j = 0; j <= i; j++){
            chmax(dp[i+1][j+1], dp[i][j] + X[i+1] + bonus[j+1]); // 表の場合
        }

        for(int j = 0; j <= N; j++){
            chmax(Maxi, dp[i+1][j]);
        }
    }

    ll ans = -1;
    for(int i = 0; i <= N; i++){
        chmax(ans, dp[N][i]);
    }
    cout << ans << endl;
    return 0;
}