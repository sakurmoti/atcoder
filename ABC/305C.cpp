#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,W;
    cin >> H >> W;

    vector<vector<char>> S(H+10,vector<char>(W+10,'.'));
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            cin >> S[i][j];
        }
    }

    int dx[] = {0,1,0,-1};
    int dy[] = {1,0,-1,0};
    for(int a = 1; a <= H; a++){
        for(int c = 1; c <= W; c++){
            if(S[a][c] == '.'){
                int cnt = 0;
                for(int i = 0; i < 4; i++){
                    if(S[a+dy[i]][c+dx[i]] == '#'){
                        cnt++;
                    }
                }

                if(cnt >= 2){
                    cout << a << " " << c << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}