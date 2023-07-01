#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int H,W;
vector<vector<char>> S;
vector<vector<bool>> visited;
string snuke = "snuke";

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void dfs(int x, int y, int cnt){
    if(visited[y][x]) return;
    if(snuke[cnt%5] != S[y][x]) return;


    visited[y][x] = true;
    
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        dfs(nx, ny, cnt+1);
    }
}

int main(){
    int H,W;
    cin >> H >> W;

    visited.resize(H+10, vector<bool>(W+10, false));
    S.resize(H+10, vector<char>(W+10, '.'));
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            cin >> S[i][j];
        }
    }

    dfs(1, 1, 0);

    if(visited[H][W]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}