#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,K; cin >> N >> K;

    /*
     dp[i][j] := iに対して 2^j 回操作したときの数字
     100a + 10b + cからa+b+cを引いても常に0以上

     dp[i][0]は愚直に計算
     dp[0][j]は全て0
     定義から dp[i][1] = dp[dp[i][0]][0]なことに注意すると
     dp[i][j] = dp[dp[i][j-1]][j-1]
    */

    vector<vector<int>> dp(N+1, vector<int>(40, 0));
    for(int i = 0; i <= N; i++){
        string s = to_string(i);
        int sum = 0;
        for(int j = 0; j < s.size(); j++){
            sum += (s[j] - '0');
        }
        dp[i][0] = i-sum;

        // printf("dp[%d][0] = %d\n",i,dp[i][0]);
    }

    for(int j = 1; j <= 30; j++){
        for(int i = 1; i <= N; i++){
            dp[i][j] = dp[dp[i][j-1]][j-1];
            // printf("dp[%d][%d] = %d\n", i,j,dp[i][j]);
        }
    }

    for(int i = 1; i <= N; i++){
        bitset<40> bit(K);
        int ans = i;
        for(int j = 0; j <= 30; j++){
            if(bit.test(j)){
                ans = dp[ans][j];
            }
        }

        cout << ans << endl;
    }
    return 0;
}