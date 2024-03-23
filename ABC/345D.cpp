#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int N,H,W;
vector<int> A,B;
bool ans = false;

bool isRange(int x, int l, int r){
    return (l <= x) && (x < r);
}

// (di, dj)を左上としてh x wの長方形を置けるか？
bool can_put(vector<vector<int>> &grid, int h, int w, int di, int dj){
    for(int i = di; i < di+h; i++){
        for(int j = dj; j < dj+w; j++){
            if(!(isRange(i, 0, H) && isRange(j, 0, W) && grid[i][j] == 0)){
                return false;
            }
        }
    }

    return true;
}

void placement(vector<vector<int>> &grid, int h, int w, int di, int dj){
    for(int i = di; i < di+h; i++){
        for(int j = dj; j < dj+w; j++){
            grid[i][j] = 1;
        }
    }
}

void replacement(vector<vector<int>> &grid, int h, int w, int di, int dj){
    for(int i = di; i < di+h; i++){
        for(int j = dj; j < dj+w; j++){
            grid[i][j] = 0;
        }
    }
}


void solve(bitset<7> &used, vector<vector<int>> &grid, int di, int dj){
    while(grid[di][dj] > 0){
        dj++;
        if(dj >= W){
            di++;
            dj=0;
        }

        if(di >= H){
            break;
        }
    }

    // 最後まで到達できた = 最後までgridが埋まった
    if(di >= H){
        ans = true;
        return;
    }

    for(int v = 0; v < N; v++){
        if(used.test(v)) continue;
                
        if(grid[di][dj] == 0){
            if( can_put(grid, A[v], B[v], di, dj) ){
                placement(grid, A[v], B[v], di, dj);
                used.set(v);
                solve(used, grid, di, dj );
                used.reset(v);
                replacement(grid, A[v], B[v], di, dj);
            }
        
            if( can_put(grid, B[v], A[v], di, dj) ){
                placement(grid, B[v], A[v], di, dj);
                used.set(v);
                solve(used, grid, di, dj);
                used.reset(v);
                replacement(grid, B[v], A[v], di, dj);
            }
        }
    }
}

int main(){
    cin >> N >> H >> W;
    A.resize(N);
    B.resize(N);
    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i];
    }

    bitset<7> used(0);
    vector<vector<int>> grid(H, vector<int>(W, 0));
    solve(used, grid, 0, 0);
    
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}