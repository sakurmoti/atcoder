#include <bits/stdc++.h>
using namespace std;

int main(){
    int W,H,N;
    cin >> W >> H >> N;

    vector<vector<bool>> S(H, vector<bool>(W, true));
    for(int i = 0; i < N; i++){
        int x,y,q;
        cin >> x >> y >> q;
        x--;
        y--;

        if(q == 1){
            for(int s = 0; s < H; s++){
                for(int t = 0; t < W; t++){
                    if(t <= x) S[s][t] = false;
                }
            }
        }

        if(q == 2){
            for(int s = 0; s < H; s++){
                for(int t = 0; t < W; t++){
                    if(t > x) S[s][t] = false;
                }
            }
        }

        if(q == 3){
            for(int s = 0; s < H; s++){
                for(int t = 0; t < W; t++){
                    if(s <= y) S[s][t] = false;
                }
            }
        }
        if(q == 4){
            for(int s = 0; s < H; s++){
                for(int t = 0; t < W; t++){
                    if(s > y) S[s][t] = false;
                }
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j]){
                //cout << "#";
                cnt++;
            }else{
                //cout << ".";
            }
        }
        //cout << endl;
    }
    cout << cnt << endl;
    return 0;
}