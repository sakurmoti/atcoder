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
    int N,X; cin >> N >> X;
    vector<tuple<int, int, int>> A(N+1);
    for(int i = 1; i <= N; i++){
        int v,a,c; cin >> v >> a >> c;
        A[i] = {v, a, c};
    }

    ll ok = 0;
    ll ng = 1e10;
    while(abs(ok-ng) > 1){
        ll mid = (ok+ng)/2;
        // ビタミン1,2,3が全てmid以上を達成できるか

        // dp[i][j] := i番目まで見たとき、カロリーがjのときの各ビタミンの摂取量
        vector<vector<tuple<ll,ll,ll>>> dp(N+1, vector<tuple<ll,ll,ll>>(X+1, {0, 0, 0}));
        for(int i = 1; i <= N; i++){
            for(int j = 0; j <= X; j++){
                dp[i][j] = dp[i-1][j];

                auto[v, a, c] = A[i];
                if(j+c <= X){
                    if(v==1){
                        int v1 = get<0>(dp[i-1][j])+a;
                        int v2 = get<0>(dp[i-1][j+c]);
                        if(v2 < v1){
                            dp[i][j+c] = make_tuple(v1, get<1>(dp[i-1][j]), get<2>(dp[i-1][j]));
                        }
                    }else if(v==2){
                        int v1 = get<1>(dp[i-1][j])+a;
                        int v2 = get<1>(dp[i-1][j+c]);
                        if(v2 < v1){
                            dp[i][j+c] = make_tuple(get<0>(dp[i-1][j]), v1, get<2>(dp[i-1][j]));
                        }
                    }else{
                        int v1 = get<2>(dp[i-1][j])+a;
                        int v2 = get<2>(dp[i-1][j+c]);
                        if(v2 < v1){
                            dp[i][j+c] = make_tuple(get<0>(dp[i-1][j]), get<1>(dp[i-1][j]), v1);
                        }
                    }

                }
            }
        }

        if(get<0>(dp[N][X]) >= mid && get<1>(dp[N][X]) >= mid && get<2>(dp[N][X]) >= mid){
            ok = mid;
        }else{
            ng = mid;
        }

    }

    cout << ok << endl;
    return 0;
}