#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int H,W,N; cin >> H >> W >> N;
    vector<vector<char>> G(H, vector<char>(W, '.'));
    
    vector<pair<int, int>> dir = {{0,-1}, {1,0}, {0,1}, {-1,0}};
    pair<int, int> now = {0,0};
    int d = 0;
    
    for(int i = 0; i < N; i++){
        if(G[now.second][now.first] == '.'){
            G[now.second][now.first] = '#';
            d = (d+1 + 4) % 4;
        }else{
            G[now.second][now.first] = '.';
            d = (d-1 + 4) % 4;
        }

        now.first = (now.first+dir[d].first + W) % W;
        now.second = (now.second+dir[d].second + H) % H;
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << G[i][j];
        }
        cout << endl;
    }
    return 0;
}