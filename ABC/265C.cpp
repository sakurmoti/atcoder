#include <bits/stdc++.h>
using namespace std;

int H,W;
vector<vector<char>> glid;
vector<vector<bool>> seen;

//glidの座標h,wのマスを確認して再帰的に動く。
//seenは行ったことがあるならtrueへ。一度行ったとこに戻るのはループしているということ
void search(int h, int w){
    char tile = glid.at(h).at(w);
    bool flag = false; //範囲外に行くときにtrueにする

    if(seen.at(h).at(w)){
        cout << -1 << endl;
        return;
    }

    seen.at(h).at(w) = true;

    if(tile == 'U'){
        if(h > 0){
            search(h-1,w);
        }else{
            flag = true;
        }

    }else if(tile == 'D'){
        if(h < H-1){
            search(h+1,w);
        }else{
            flag = true;
        }

    }else if(tile == 'L'){
        if(w > 0){
            search(h,w-1);
        }else{
            flag = true;
        }

    }else if(tile == 'R'){
        if(w < W-1){
            search(h,w+1);
        }else{
            flag = true;
        }

    }

    if(flag) cout << h+1 << " " << w+1 << endl;
}

int main(){
    cin >> H >> W;
    
    glid.resize(H, vector<char>(W));
    seen.resize(H, vector<bool>(W,false));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> glid.at(i).at(j);
        }
    }
    
    search(0,0);
    return 0;
}