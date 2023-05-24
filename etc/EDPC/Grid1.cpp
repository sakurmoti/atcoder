#include <bits/stdc++.h>
using namespace std;

const int modulo = (1e9) + 7;

int H,W;
vector<string> world;
/*dp[y][x]を(0,0)から(x,y)までの道の総数とする
dp[y][x] = dp[y-1][x] + dp[y][x-1]*/
vector<vector<int>> dp;

int main(){
    cin >> H >> W;

    world.resize(H);
    dp.resize(H, vector<int>(W,0));
    for(int i = 0; i < H; i++){
        cin >> world.at(i);
    }

    dp.at(0).at(0) = 1;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(world.at(i).at(j) == '#') continue;

            if(i != 0) dp.at(i).at(j) += dp.at(i-1).at(j);
            if(j != 0) dp.at(i).at(j) += dp.at(i).at(j-1);
        
            dp.at(i).at(j) %= modulo;
        }
    }

    cout << dp.at(H-1).at(W-1);

    return 0;
}