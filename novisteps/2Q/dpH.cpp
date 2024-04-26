#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;

template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }

int main(){
    int H,W; cin >> H >> W;
    vector<vector<char>> grid(H+1, vector<char>(W+1));
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            cin >> grid[i][j];
        }
    }

    vector<vector<mint>> dp(H+1, vector<mint>(W+1,0));
    dp[1][1] = 1;
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            if(isRange(j+1,1,W+1) && grid[i][j+1] == '.'){
                dp[i][j+1] += dp[i][j];
            }

            if(isRange(i+1,1,H+1) && grid[i+1][j] == '.'){
                dp[i+1][j] += dp[i][j];
            }
        }
    }

    cout << dp[H][W].val() << endl;
    return 0;
}