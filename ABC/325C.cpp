#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int H,W;
vector<vector<char>> S;
vector<vector<bool>> visited;

// 上から時計回り
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
void dfs(int x, int y){
    if(visited.at(y).at(x)) return;
    visited[y][x] = true;

    for(int i = 0; i < 8; i++){
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if(S.at(next_y).at(next_x) == '#'){
            dfs(next_x, next_y);
        }
    }
}

int main(){
    cin >> H >> W;
    S.resize(H+10, vector<char>(W+10, '.'));
    visited.assign(H+10, vector<bool>(W+10, false));
    
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            cin >> S[i][j];
        }
    }

    int ans = 0;
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            if( (S[i][j] == '#') && (visited[i][j] == false)){
                ans++;
                dfs(j,i);
            }
        }
    }
    cout << ans << endl;
    return 0;
}