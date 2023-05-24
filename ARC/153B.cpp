#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,W;
    cin >> H >> W;

    vector<vector<char>> A(H, vector<char>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> A.at(i).at(j);
        }
    }

    //回転行列は{(cos,-sin),(sin,cos)}
    //180度回すなら{(-1,0),(0,-1)}
    //x' = -x
    //y' = -y

    int Q;
    cin >> Q;
    for(int q = 0; q < Q; q++){
        int a,b;
        cin >> a >> b;

        
    }
    return 0;
}