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

#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

int main(){
    int N,K; cin >> N >> K;
    string S; cin >> S;

    // dp[i][T] := 長さiで末尾(K-1)文字がTとなる、条件を満たす個数
    vector<map<string, mint>> dp(N+1);
    dp[0][""] = 1;

    auto isPalin = [](string T){
        int M = T.size();
        for(int i = 0; i < M; i++){
            if(T[i] != T[M-1-i]) return false;
        }
        return true;
    };

    for(int i = 0; i < N; i++){
        // cout << i << "\n";
        auto dict = dp[i];
        for(auto [k,v] : dict){
            // 末尾K-1文字の切り抜き
            string cp;
            if(k.size() >= K) cp = k.substr(1);
            else cp = k;
            // cout << cp+S[i] << endl;

            if(S[i] == '?'){
                if(cp.size() < K-1 || !isPalin(cp+"A")) dp[i+1][cp+"A"] += dp[i][k];
                if(cp.size() < K-1 || !isPalin(cp+"B")) dp[i+1][cp+"B"] += dp[i][k];

            }else{
                if(cp.size() < K-1 || !isPalin(cp+S[i])) dp[i+1][cp+S[i]] += dp[i][k];

            }

        }
    }

    mint ans = 0;
    for(auto [k,v] : dp[N]) ans += v;
    cout << ans.val() << endl;
    return 0;
}