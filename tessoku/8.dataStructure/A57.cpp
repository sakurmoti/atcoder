#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,Q; cin >> N >> Q;
    vector<int> A(N);
    for(auto &_v : A){
        cin >> _v;
        _v--;
    }
    
    /*
     dp[i][j] := i番目の穴から 2^j 日後の穴の場所
     dp[i][0]は明らかにA[i]
     dp[i][1]はdp[i][0]の翌日なので dp[dp[i][0]][0]
     dp[i][2]はdp[i][1]の二日後なので dp[dp[i][1]][1]

     一般に
     dp[i][j]はdp[i][j-1]の 2^(j-1) 日後なので dp[dp[i][j-1][j-1]
    */
    vector<vector<int>> dp(N, vector<int>(40, -1));
    for(int i = 0; i < N; i++){
        dp[i][0] = A[i];
    }

    for(int j = 1; j <= 40; j++){
        for(int i = 0; i < N; i++){
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }

    while(Q--){
        int X,Y;
        cin >> X >> Y;
        X--;

        bitset<40> Z(Y);
        for(int i = 0; i < 40; i++){
            if(Z.test(i)){
                X = dp[X][i];
            }
        }

        // cout << '\t';
        cout << X+1 << endl;
    }
    return 0;
}