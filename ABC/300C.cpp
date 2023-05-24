#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int H,W,N;
vector<int> S;
vector<vector<char>> C;
vector<vector<bool>> visited;

bool isDomain(int y, int x){
    return (0<=x && x<W && 0<=y && y<H) ? true : false;
}

void dfs(int y, int x, int cnt){
    if(visited[y][x]) return;

    visited[y][x] = true;
    int dx[] = {1,1,-1,-1};
    int dy[] = {1,-1,-1,1};
    bool isCenter = true;
    for(int i = 0; i < 4; i++){
        //定義域の外、または四方が#でないなら真ん中ではない
        if(!isDomain(y+dy[i],x+dx[i]) || C[y+dy[i]][x+dx[i]] != '#'){
            isCenter = false;
        }
    }

    if(isCenter) S.at(cnt)++;

    for(int i = 0; i < 4; i++){
        if(isDomain(y+dy[i],x+dx[i]) && C[y+dy[i]][x+dx[i]] == '#'){
            dfs(y+dy[i], x+dx[i], cnt+1);
        }
    }

}

int main(){
    cin >> H >> W;

    C.resize(H+10,vector<char>(W+10, '.'));
    visited.resize(H, vector<bool>(W, false));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> C[i][j];
        }
    }

    N = min(H,W);
    S.resize(N+1,0);

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(C[i][j] == '#'){
                dfs(i,j,0);
            }
        }
    }

    for(int i = 1; i <= N; i++){
        cout << S[i] << " ";
    }
    return 0;
}