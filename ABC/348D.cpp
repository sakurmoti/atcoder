#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int H,W,N;
vector<string> A;
map<pair<int,int> , pair<int, bool>> E; // E[p] := {エネルギーeにする, 使用済みかどうか}
vector<vector<int>> visited; // visited[i][j] := (i,j)を訪れたときの最大エネルギー
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

bool isRange(int x, int l, int r){return (l <= x) && (x < r);}

void dfs(pair<int, int> p, int e){
    if(visited[p.first][p.second] >= e) return;
    visited[p.first][p.second] = e;

    // printf("(%d,%d) e = %d\n", p.first,p.second,e);
    if(E.contains(p) && E[p].second && e < E[p].first){
        e = E[p].first;
        E[p].second = false;
    }

    for(int i = 0; i < 4; i++){
        int n1 = p.first + dy[i];
        int n2 = p.second + dx[i];
        if(! (isRange(n1,0,H) && isRange(n2,0,W)) ){
            continue;
        }

        pair<int, int> next = make_pair(n1, n2);
        if(A[n1][n2] == '#') continue;

        if(e-1 >= 0) dfs(next, e-1);
    }

    if(E.contains(p)) E[p].second = true;

}

int main(){
    start = chrono::system_clock::now();

    cin >> H >> W;
    A.resize(H);
    visited.resize(H, vector<int>(W, -1));
    for(auto &_v : A) cin >> _v;

    cin >> N;

    for(int i = 0; i < N; i++){
        int r,c,e;
        cin >> r >> c >> e;
        r--;
        c--;

        E[make_pair(r,c)] = make_pair(e, true);
    }

    pair<int, int> s,t;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(A[i][j] == 'S'){
                s = make_pair(i,j);
            }

            if(A[i][j] == 'T'){
                t = make_pair(i,j);
            }
        }
    }

    int e = 0;
    dfs(s, e);

    if(visited[t.first][t.second] >= 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}