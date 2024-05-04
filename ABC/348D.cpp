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
    pair<int, int> s,t;
    vector<vector<char>> G(H, vector<char>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> G[i][j];
            if(G[i][j] == 'S') s = make_pair(i,j);
            if(G[i][j] == 'T') t = make_pair(i,j);
        }
    }

    int N; cin >> N;
    bool isExistGoalMed = false;
    vector<tuple<int,int,int>> med(N);
    for(int i = 0; i < N; i++){
        int r,c,e; cin >> r >> c >> e;
        r--; c--;
        med[i] = make_tuple(r,c,e);

        if(r == H-1 && c == W-1) isExistGoalMed = true;
    }
    if(isExistGoalMed) med.push_back(make_tuple(H-1,W-1,0)); // 仮の薬を置く

    constexpr int dx[4] = {0, 1, 0, -1};
    constexpr int dy[4] = {1, 0, -1, 0};

    // 薬iからjまで他の薬を経由せずに到達できるか？
    for(int i = 0; i < N; i++){
        auto [r,c,e] = med[i];

        stack<pair<int, int>> st;
        
    }

    return 0;
}