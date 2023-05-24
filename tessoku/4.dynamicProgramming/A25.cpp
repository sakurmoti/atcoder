#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,W;
    cin >> H >> W;

    vector<vector<char>> A(H+1, vector<char>(W+1));
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            cin >> A.at(i).at(j);
        }
    }

    vector<vector<long long>> dp(H+1, vector<long long>(W+1,0));
    dp[1][1] = 1;
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            if(A.at(i).at(j) == '.'){
                //上からくるか、左からくるか
                dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i-1).at(j) + dp.at(i).at(j-1));

            }else{
                //黒マスに行く方法はない -> 0
                dp.at(i).at(j) = 0;

            }
        }
    }

    cout << dp.at(H).at(W) << endl;
    return 0;
}