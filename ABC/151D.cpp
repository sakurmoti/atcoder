#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int H,W; cin >> H >> W;
    vector<string> S(H);

    for(auto &_v : S) cin >> _v;

    vector<vector<bool>> init(H, vector<bool>(W, false));
    int dx[] = {1,0,-1,0};
    int dy[] = {0,-1,0,1};

    auto bfs = [&](int Y, int X){
        vector<vector<int>> dist(H, vector<int>(W, 1e9));
        dist[Y][X] = 0;

        auto visited = init;
        visited[Y][X] = true;
        
        queue<pair<int,int>> que;
        que.push(make_pair(X,Y));

        while(!que.empty()){
            int x,y;
            tie(x,y) = que.front();
            que.pop();

            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(0 <= nx && nx < W && 0 <= ny && ny < H && S[ny][nx] == '.' && !visited[ny][nx]){
                    dist[ny][nx] = dist[y][x] + 1;
                    visited[ny][nx] = true;
                    que.push(make_pair(nx, ny));
                }
            }
        }

        // for(auto v : dist){
        //     for(auto u : v){
        //         cout << u << " ";
        //     }
        //     cout << endl;
        // }

        int ret = -1;
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                if(dist[i][j] > 1e8) continue;
                ret = max(ret, dist[i][j]);
            }
        }
        return ret;
    };

    int ans = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j] == '#') continue;
            int d = bfs(i,j);
            ans = max(ans, d);
        }
    }

    cout << ans << endl;
    return 0;
}