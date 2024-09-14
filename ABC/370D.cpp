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
    int H,W,Q; cin >> H >> W >> Q;
    vector<set<int>> row(H), column(W);
    
    set<int> init;
    for(int i = 0; i < H; i++) init.insert(i);
    for(int j = 0; j < W; j++) column[j] = init;
    
    init.clear();
    for(int j = 0; j < W; j++) init.insert(j);
    for(int i = 0; i < H; i++) row[i] = init;
    
    vector<vector<char>> wall(H, vector<char>(W, '#'));
    while(Q--){
        int R,C; cin >> R >> C;
        R--; C--;

        // 壁がある場合
        if(row[R].contains(C)){
            row[R].erase(C);
            column[C].erase(R);
            wall[R][C] = ' ';
            continue;
        }

        // ないとき
        auto up = column[C].lower_bound(R);
        if(up != column[C].begin()){
            int u = *prev(up); // 要素が1個かつ(R,C)が空は保障されているので一個前が上側
            column[C].erase(u);
            row[u].erase(C);
            wall[u][C] = ' ';
        }

        auto down = column[C].lower_bound(R);
        if(down != column[C].end()){
            int d = *down;
            column[C].erase(d);
            row[d].erase(C);
            wall[d][C] = ' ';
        }

        auto left = row[R].lower_bound(C);
        if(left != row[R].begin()){
            int l = *prev(left);
            column[l].erase(R);
            row[R].erase(l);
            wall[R][l] = ' ';
        }

        auto right = row[R].lower_bound(C);
        if(right != row[R].end()){
            int r = *right;
            column[r].erase(R);
            row[R].erase(r);
            wall[R][r] = ' ';
        }

        // for(auto &_v : wall){ for(auto &_vv : _v) cout << _vv; cout << endl; }
    }

    int cnt = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(wall[i][j] == '#') cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}