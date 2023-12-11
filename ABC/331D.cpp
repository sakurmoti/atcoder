#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,Q; cin >> N >> Q;
    vector<string> P(N);
    for(auto &_v : P) cin >> _v;

    // grid[i][j] := H=[0,i), W=[0,j) 区間の黒マスの個数 
    vector<vector<ll>> grid(N+1, vector<ll>(N+1, 0));
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(P[i-1][j-1] == 'B') grid[i][j]++;
            grid[i][j] += grid[i-1][j];
            grid[i][j] += grid[i][j-1];
            grid[i][j] -= grid[i-1][j-1];
        }
    }

    auto f = [&](int A, int B, int C, int D){
        // A <= h < C, B <= w < Dの範囲内の黒マスを求める

        auto g = [&](int H, int W) -> ll {
            // 0 <= h < H, 0 <= w < Wの範囲内の黒マスを求める
            ll ret = 0;

            // Pに含まれる黒マス
            ll column = H/N;
            ll row = W/N;
            
            ret += (row * column * grid[N][N]);

            // rowのあまり
            int mod_row = W%N;
            ret += (column * grid[N][mod_row]);

            // columnのあまり
            int mod_column = H%N;
            ret += (row * grid[mod_column][N]);

            // 両者のあまり
            ret += grid[mod_column][mod_row];

            return ret;
        };

        return g(C,D) - g(C,B) - g(A,D) + g(A,B);
    };

    for(int q = 0; q < Q; q++){
        int A,B,C,D;
        cin >> A >> B >> C >> D;

        cout << f(A, B, C+1, D+1) << endl;
    }
    return 0;
}