#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
struct Point{int x, y;};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int H,W; cin >> H >> W;
    int sx,sy,gx,gy;
    vector<vector<char>> A(H, vector<char>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> A[i][j];
            if(A[i][j] == 'T'){
                gx=j;
                gy=i;
            }else if(A[i][j] == 'S'){
                sx = j;
                sy = i;
            }
        }
    }

    int N; cin >> N;
    vector<tuple<int,int,int>> med(N);
    int st = -1;
    for(int i = 0; i < N; i++){
        int r,c,e; cin >> r >> c >> e;
        r--; c--;
        med[i] = make_tuple(r,c,e);

        if(sy==r && sx == c) st = i;
    }
    med.push_back(make_tuple(gy,gx,0)); // ゴールに疑似的な薬を置く
    
    if(st < 0){ // スタートに薬がないと動けない
        cout << "No" << endl;
        return 0;
    }

    auto bfs = [&](int st) -> vector<bool> {
        vector<bool> ret(N+1, false);
        vector<vector<bool>> visited(H, vector<bool>(W,false));
        queue<tuple<int,int,int>> que;
        que.push(med[st]);
        while(!que.empty()){
            auto[y,x,e] = que.front();
            que.pop();

            if(visited[y][x]) continue;
            visited[y][x] = true;
            for(int i = 0; i < 4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(e > 0 && isRange(nx,0,W) && isRange(ny,0,H) && A[ny][nx] != '#'){
                    que.push(make_tuple(ny,nx,e-1));
                }
            }
        }

        for(int i = 0; i <= N; i++){
            auto[y,x,e] = med[i];
            if(visited[y][x]) ret[i] = true;
        }

        return ret;
    };

    vector<vector<bool>> canVisit(N+1);
    for(int i = 0; i <= N; i++){
        canVisit[i] = bfs(i);
    }

    // ワーシャルフロイド
    for(int k = 0; k <= N; k++){
        for(int i = 0; i <= N; i++){
            for(int j = 0; j <= N; j++){
                if(canVisit[i][k] && canVisit[k][j]){
                    canVisit[i][j] = true;
                }
            }
        }
    }

    if(canVisit[st][N]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}