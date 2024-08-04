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
    int N; cin >> N;
    string S; cin >> S;

    auto Janken = [&](char A, char T){
        // -1 : 負け, 0 : 引き分け, 1 : 勝ち
        if(A=='R'){
            if(T=='R'){
                return 0;
            }else if(T=='P'){
                return 1;
            }else if(T=='S'){
                return -1;
            }
        }else if(A=='P'){
            if(T=='R'){
                return -1;
            }else if(T=='P'){
                return 0;
            }else if(T=='S'){
                return 1;
            }
        }else if(A=='S'){
            if(T=='R'){
                return 1;
            }else if(T=='P'){
                return -1;
            }else if(T=='S'){
                return 0;
            }
        }
        return 0;
    };

    // dp[i][j] := i回目まで見たとき、前回j={0:R,1:P,2:S}を出した時に勝った回数としてありえる最大値
    vector<vector<int>> dp(N+1, vector<int>(3, -1e9));
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;

    string Takahashi = "RPS";
    for(int i = 1; i <= N; i++){
        char Aoki = S[i-1];

        for(int j = 0; j < 3; j++){
            int res = Janken(Aoki, Takahashi[j]);
            
            for(int k = 0; k < 3; k++){
                if(res < 0 || j==k) continue;
                chmax(dp[i][j], dp[i-1][k] + res);
            }
        }
    }

    cout << max({dp[N][0], dp[N][1], dp[N][2]}) << endl;
    return 0;
}