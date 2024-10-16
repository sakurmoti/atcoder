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
    int N; cin >> N;
    vector<int> X(N), Y(N);
    for(int i = 0; i < N; i++){
        cin >> X[i] >> Y[i];
    }

    // dp[i][j] := i番目まで見たとき、お腹を壊している,または壊していない(j={0,1})ときの美味しさの最大値
    vector<vector<ll>> dp(N+1, vector<ll>(2, -1e18));
    dp[0][0] = 0;
    for(int i = 0; i < N; i++){
        if(X[i] == 0){
            chmax(dp[i+1][0], max({dp[i][0], dp[i][0]+Y[i], dp[i][1]+Y[i]}));
            chmax(dp[i+1][1], dp[i][1]);
        }else{
            chmax(dp[i+1][0], dp[i][0]);
            chmax(dp[i+1][1], max(dp[i][1], dp[i][0]+Y[i]));
        }
    } 

    cout << max(dp[N][0], dp[N][1]) << endl;
    return 0;
}