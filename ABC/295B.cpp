#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int R,C;
    cin >> R >> C;

    vector<vector<char>> B(R, vector<char>(C));
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> B[i][j];
        }
    }

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(B[i][j] != '.' && B[i][j] != '#'){
                int k = B[i][j] - '0';
                
                B[i][j] = '.';
                for(int s = 0; s <= k; s++){
                    int x,y;
                    for(int t = 0; t <= k; t++){
                        if(s+t > k) break;
                        //printf("s=%d, t=%d\n",s,t);

                        y = i+s;
                        x = j+t;
                        if(0 <= x && x < C && 0 <= y && y < R){
                            if(B[y][x] == '#') B[y][x] = '.';
                        }

                        y = i+s;
                        x = j-t;
                        if(0 <= x && x < C && 0 <= y && y < R){
                            if(B[y][x] == '#') B[y][x] = '.';
                        }

                        y = i-s;
                        x = j+t;
                        if(0 <= x && x < C && 0 <= y && y < R){
                            if(B[y][x] == '#') B[y][x] = '.';
                        }

                        y = i-s;
                        x = j-t;
                        if(0 <= x && x < C && 0 <= y && y < R){
                            if(B[y][x] == '#') B[y][x] = '.';
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout << B[i][j];
        }
        cout << endl;
    }
    return 0;
}