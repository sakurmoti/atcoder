#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    string T; cin >> T;
    int lenT = T.size();
    int N; cin >> N;

    vector<ll> dp(lenT+1, 1e18);
    dp[0] = 0;
    for(int i = 0; i < N; i++){
        int A; cin >> A;
        auto ndp = dp;
        for(int j = 0; j < A; j++){
            string S; cin >> S;
            int lenS = S.size();

            for(int t = 0; t <= (lenT - lenS); t++){
                string subT = T.substr(t, lenS);

                if(subT == S){
                    ndp[t+lenS] = min(ndp[t+lenS], dp[t] + 1);
                }
            }
        }

        dp = ndp;

        // for(auto &_v : dp) cout << _v << " "; cout << endl;
    }

    cout << (dp[lenT] > 1e17 ? -1 : dp[lenT]) << endl;
    return 0;
}