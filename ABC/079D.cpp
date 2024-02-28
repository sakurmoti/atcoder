#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int H,W; cin >> H >> W;
    vector<vector<int>> C(10, vector<int>(10));
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin >> C[i][j];
        }
    }

    // dist[i][j] := i から j に変換する最小コスト
    vector<vector<int>> dist = C;
    for(int k = 0; k < 10; k++){
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    

    ll sum = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            int a; cin >> a;
            if(a < 0) continue;
            sum += dist[a][1];
        }
    }

    cout << sum << endl;
    return 0;
}