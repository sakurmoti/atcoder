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

#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

int main(){
    int N; cin >> N;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    // dp[i][j][k] := Ai, Ajを固定したとき長さkの等差数列の組合せ
    vector<vector<vector<mint>>> dp(N, vector<vector<mint>>(N, vector<mint>(N+1, 0)));
    for(int i = 0; i < N; i++){
        dp[i][i][1] = 1;
    }

    for(int i = N-1; i >= 0; i--){
        for(int j = i+1; j < N; j++){
            for(int k = 2; k <= N; k++){
                if(k==2){
                    dp[i][j][2]++;
                    continue;
                }

                int d = A[j] - A[i];
                for(int l = j+1; l < N; l++){
                    if(A[l]-A[j] == d){
                        dp[i][j][k] += dp[j][l][k-1];
                    }
                }

            }
        }
    }

    vector<mint> ans(N+1,0);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 1; k <= N; k++){
                ans[k] += dp[i][j][k];
            }
        }
    }

    for(int i = 1; i <= N; i++){
        cout << ans[i].val() << " ";
    }
    return 0;
}