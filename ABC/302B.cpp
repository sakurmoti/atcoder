#include <bits/stdc++.h>
using namespace std;

int H,W;
bool domain(int x, int y){
    return (0<=x && x<W && 0<=y && y<H) ? true : false;
}

int main(){
    cin >> H >> W;

    vector<string> S(H);
    for(int i = 0; i < H; i++){
        cin >> S[i];
    }

    int dx[] = {0,1,1,1,0,-1,-1,-1};
    int dy[] = {1,1,0,-1,-1,-1,0,1};
    string snuke = "snuke";
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j] == 's'){
                //8方向
                for(int k = 0; k < 8; k++){
                    //何文字目か
                    bool flag = true;
                    vector<pair<int, int>> ans;
                    for(int l = 0; l < 5; l++){
                        int y = i+l*dy[k];
                        int x = j+l*dx[k];
                        if(domain(x,y) && S.at(y).at(x) == snuke[l]){
                            ans.push_back(make_pair(y+1,x+1));
                            continue;

                        }else{
                            flag = false;
                        }
                    }

                    if(flag){
                        for(auto v : ans){
                            cout << v.first << " " << v.second << endl;
                        }
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}