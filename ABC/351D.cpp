#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int H,W; cin >> H >> W;
    vector<vector<char>> S(H+10, vector<char>(W+10, '+'));
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            cin >> S[i][j];
        }
    }

    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    vector<vector<int>> free(H+1, vector<int>(W+1, -1));
    
    auto bfs = [&](int y1, int x1, int id) {
        int ret = 0;
        stack<pair<int, int>> st;
        st.push(make_pair(x1,y1));

        while(!st.empty()){
            auto [x,y] = st.top();
            st.pop();

            if(free[y][x] == id) continue;
            free[y][x] = id;

            bool isNearMag = false;
            vector<pair<int, int>> cor;
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(S[ny][nx] == '#'){
                    isNearMag = true;
                }else if(S[ny][nx] == '.' && free[ny][nx] != id){
                    cor.push_back(make_pair(nx,ny));
                }
            }

            if(!isNearMag){
                for(auto v : cor) st.push(v);
            }

            ret++;
        }

        return ret;
    };
    
    int ans = 1;
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            if(free[i][j] < 0 && S[i][j] != '#'){
                int score = bfs(i,j, (i-1)*W + j);
                if(score > ans){
                    ans = score;
                    // cout << i << " " << j << endl;
                }
            }
        }
    }

    for(auto &_v : free){ for(auto &_vv : _v) cout << _vv << " "; cout << endl; }
    cout << ans << endl;
    return 0;
}