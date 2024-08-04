#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int H,W; cin >> H >> W;
    int sx,sy; cin >> sy >> sx;
    sx--;
    sy--;

    vector<string> C;
    for(int i = 0; i < H; i++){
        string s; cin >> s;
        C.push_back(s);
    }

    string S; cin >> S;
    map<char, pair<int, int>> d;
    d['L'] = {0,-1};
    d['R'] = {0,1};
    d['U'] = {-1, 0};
    d['D'] = {1,0};

    pair<int, int> now = make_pair(sy, sx);
    for(int i = 0; i < S.size(); i++){
        char c = S[i];
        auto[y, x] = now;

        auto[dy,dx] = d[c];

        int nx = x + dx;
        int ny = y + dy;
        if(isRange(ny,0,H) && isRange(nx,0,W) && C[ny][nx] != '#'){
            now = make_pair(ny,nx);
        }

        // cout << now.first << " " << now.second << endl;
    }

    cout << now.first+1 << " " << now.second+1 << endl;
    return 0;
}