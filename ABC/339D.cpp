#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    vector<string> S(N);
    for(auto &_v : S) cin >> _v;


    int sx=-1,sy,tx,ty;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(S[i][j] == 'P'){
                if(sx < 0){
                    sx = j;
                    sy = i;
                }else{
                    tx = j;
                    ty = i;
                }
            }
        }
    }

    auto inRange = [&N](int X) ->bool {
        return (0 <= X && X < N);
    };

    auto chmin = [](int &a, int b) -> bool {
        if(a > b){
            a = b;
            return true;
        }else{
            return false;
        }
    };

    // 二人のプレイヤーの位置で盤面を管理する
    // G[x][y][z][w] := その座標にプレイヤーが集まるまでの最短回数
    using quater = tuple<int,int,int,int>;
    
    vector<vector<vector<vector<int>>>> G(N, vector<vector<vector<int>>>(N, vector<vector<int>>(N, vector<int>(N, 1e9))));
    queue<quater> que;
    que.push(quater{sx,sy,tx,ty});
    G[sx][sy][tx][ty] = 0;

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};
    while(!que.empty()){
        auto v = que.front();
        que.pop();

        tie(sx,sy,tx,ty) = v;
        for(int i = 0; i < 4; i++){
            int nsx,nsy,ntx,nty;

            nsx = sx + dx[i];
            nsy = sy + dy[i];
            if(not (inRange(nsx) && inRange(nsy) && S[nsy][nsx] != '#')){
                nsx = sx;
                nsy = sy;
            }

            ntx = tx + dx[i];
            nty = ty + dy[i];
            if(not (inRange(ntx) && inRange(nty) && S[nty][ntx] != '#')){
                ntx = tx;
                nty = ty;
            }

            if( chmin(G[nsx][nsy][ntx][nty], G[sx][sy][tx][ty]+1) ){
                que.push(quater{nsx,nsy,ntx,nty});
            }
        }
    }

    int ans = 1e9;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            chmin(ans, G[i][j][i][j]);
        }
    }

    if(ans > 1e8) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}