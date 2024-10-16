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
    string T; cin >> T;
    int N; cin >> N;
    int lenT = T.size();

    // dp[i] := T[i]まで一致させるのに最小の値段
    vector<int> dp(lenT+1, 1e9);
    dp[0] = 0;
    for(int i = 0; i < N; i++){
        int A; cin >> A;
        auto cp = dp;

        for(int j = 0; j < A; j++){
            string S; cin >> S;
            int lenS = S.size();

            for(int k = 0; k < lenT; k++){
                string subT = T.substr(k, lenS);
                if(subT==S){
                    chmin(cp[k+lenS], dp[k]+1);
                }
            }

        }

        dp = cp;
    }

    // for(auto &_v : dp) cout << _v << " "; cout << endl;

    if(dp[lenT] > 1e8) cout << -1 << endl;
    else cout << dp[lenT] << endl;
    return 0;
}