#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

template<class T>
bool chmin(T &x, T y){
    if(x > y){
        x = y;
        return true;
    }
    return false;
}

int main(){
    string T; cin >> T;
    int lenT = T.size();
    int N; cin >> N;

    // dp[i] := i文字目まで一致させるための最小の金額
    vector<int> dp(lenT+1, 1e9);
    dp[0] = 0;
    for(int i = 0; i < N; i++){
        int A; cin >> A;
        auto cp = dp;

        for(int j = 0; j < A; j++){
            string S; cin >> S;
            int M = S.size();

            // Tの[st, st+M)がSと一致しているか
            for(int st = 0; st <= lenT-M; st++){
                bool flag = true;
                for(int k = 0; k < M; k++){
                    if(T[st+k] != S[k]){
                        flag = false;
                        break;
                    }
                }

                if(flag){
                    chmin(cp[st+M], dp[st]+1);
                }
            }
        }

        dp = cp;
    }

    // for(auto &v : dp) cout << v << " ";
    if(dp[lenT] > 1e8) dp[lenT] = -1;
    cout << dp[lenT] << endl;
    return 0;
}