#include <bits/stdc++.h>
using namespace std;

struct point{
    int x;
    int y;
};

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main(){
    int R,C;
    cin >> R >> C;

    point s,g;
    cin >> s.y >> s.x >> g.y >> g.x;
    s.y--; s.x--;
    g.y--; g.x--;
    
    vector<vector<char>> world(R, vector<char> (C, '#'));
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> world.at(i).at(j);
        }
    }

    queue<point> que;
    vector<vector<int>> ans(R, vector<int> (C,-1));
    ans[s.y][s.x] = 0;
    que.push({s.x,s.y});

    while(!que.empty()){
        point now = que.front();
        que.pop();

        for(int i = 0; i < 4; i++){
            int px = now.x + dx[i];
            int py = now.y + dy[i];
            if(world.at(py).at(px) == '.' && ans.at(py).at(px) < 0){
                ans.at(py).at(px) = ans.at(now.y).at(now.x) + 1;
                que.push({px,py});
            }
        }
    }

    cout << ans[g.y][g.x] << endl;
    return 0;
}