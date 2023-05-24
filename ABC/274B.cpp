#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,W;
    cin >> H >> W;

    char Q;
    vector<int> ans(W,0);
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> Q;
            if(Q == '#'){
                ans.at(j)++;
            }
        }
    }

    for(int i = 0; i < W; i++){
        cout << ans.at(i);
        if(i != W-1) cout  << " ";
        else cout << endl;
    }
    return 0;
}