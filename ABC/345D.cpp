#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int N,H,W;
vector<int> A,B;

bool isRange(int x, int L, int R){
    return ( (L <= x) && (x < R) );
}

// h x w の長方形を(di, dj)を左上の位置としておけるか
// O(hw)
bool can_put(vector<vector<int>> grid, int h, int w, int di, int dj){
    for(int i = di; i < di+h; i++){
        for(int j = dj; j < dj+w; j++){
            if(!isRange(i, 0, H) || !isRange(j, 0, W) || (grid[i][j] != 0) ){
                return false;
            }
        }
    }

    return true;
};

// usedを全て用いてgridを埋めれるか?
// O(H^2 W^2)
bool solve(vector<int> &used, vector<vector<int>> &grid, vector<bool> &isUsed){
    // for(auto u : grid){
    //     for(auto v : u){
    //         cout << v;
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    for(auto v : used){
        if(isUsed[v]) continue;

        for(int h = 0; h < H; h++){
            for(int w = 0; w < W; w++){
                if(can_put(grid, A[v], B[v], h, w)){
                    // cout << "canput 1\n";
                    // grid塗り
                    vector<vector<int>> g = grid;
                    for(int i = h; i < h+A.at(v); i++){
                        for(int j = w; j < w+B.at(v); j++){
                            g[i][j] = 1;
                        }
                    }
                    
                    isUsed[v] = true;
                    solve(used, g, isUsed);
                    isUsed[v] = false;
                    
                }

                // 90'回転
                if(can_put(grid, B[v], A[v], h, w)){
                    // cout << "canput 2\n";
                    vector<vector<int>> g = grid;
                    for(int i = h; i < h+B[v]; i++){
                        for(int j = w; j < w+A[v]; j++){
                            g[i][j] = 1;
                        }
                    }
                    
                    isUsed[v] = true;
                    solve(used, g, isUsed);
                    isUsed[v] = false;
                    
                }
            }
        }
    }

    for(auto v : grid){
        for(auto u : v){
            if(u==0){return false;}
        }
    }

    return true;
};

int main(){
    cin >> N >> H >> W;
    A.resize(N);
    B.resize(N);
    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i];
    }


    // O(2^7 = 128)
    vector<vector<int>> g_init(H, vector<int>(W, 0));
    vector<bool> isused_init(10, false);
    for(int b = 0; b < (1 << 8); b++){
        bitset<10> bits(b);

        vector<int> used;
        for(int i = 0; i < N; i++){
            if(bits.test(i)){
                used.push_back(i);
            }
        }

        if(solve(used, g_init, isused_init)){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}