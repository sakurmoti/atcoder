#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int H,W,K;
    cin >> H >> W >> K;

    vector<vector<char>> S(H+1, vector<char>(W+1, '-'));
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            cin >> S[i][j];
        }
    }

    int ans = 1e9;

    vector<vector<int>> cum_X(H+1, vector<int>(W+1, 0));
    vector<vector<int>> cum_dot(H+1, vector<int>(W+1, 0));
    
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            if(S[i][j] == 'o'){
                cum_X[i][j] = cum_X[i][j-1];
                cum_dot[i][j] = cum_dot[i][j-1];

            }else if(S[i][j] == 'x'){
                cum_X[i][j] = cum_X[i][j-1] + 1;
                cum_dot[i][j] = cum_dot[i][j-1];

            }else if(S[i][j] == '.'){
                cum_X[i][j] = cum_X[i][j-1];
                cum_dot[i][j] = cum_dot[i][j-1] + 1;

            }
        }
    
        for(int j = 0; j+K <= W; j++){
            int x = cum_X[i][j+K] - cum_X[i][j];
            int dot = cum_dot[i][j+K] - cum_dot[i][j];
            if(x == 0){
                ans = min(ans, dot);
            } 
        }
    }

    for(int j = 1; j <= W; j++){
        for(int i = 1; i <= H; i++){
            if(S[i][j] == 'o'){
                cum_X[i][j] = cum_X[i-1][j];
                cum_dot[i][j] = cum_dot[i-1][j];

            }else if(S[i][j] == 'x'){
                cum_X[i][j] = cum_X[i-1][j] + 1;
                cum_dot[i][j] = cum_dot[i-1][j];

            }else if(S[i][j] == '.'){
                cum_X[i][j] = cum_X[i-1][j];
                cum_dot[i][j] = cum_dot[i-1][j] + 1;

            }
        }
    
        for(int i = 0; i+K <= H; i++){
            int x = cum_X[i+K][j] - cum_X[i][j];
            int dot = cum_dot[i+K][j] - cum_dot[i][j];
            if(x == 0){
                ans = min(ans, dot);
            } 
        }
    }

    if(ans <= K) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}