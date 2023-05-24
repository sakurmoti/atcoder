#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int H,W;
vector<vector<int>> A;

int ans = 0;
set<int> route;

void dfs(int x, int y){
    if(route.count(A.at(y).at(x))){
        return;

    }else{
        route.insert(A.at(y).at(x));
    }

    if(x==W-1 && y==H-1) ans++;

    if(0 <= x && x < W-1){
        dfs(x+1,y);
    }

    if(0 <= y && y < H-1){
        dfs(x, y+1);
    }

    route.erase(A.at(y).at(x));
}

int main(){
    cin >> H >> W;

    A.resize(H, vector<int>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> A[i][j];
        }
    }

    dfs(0,0);

    cout << ans << endl;
    return 0;
}