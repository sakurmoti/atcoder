#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    string R,C; cin >> R >> C;

    vector<char> K = {'A','B','C'};
    K.resize(N, '.');

    vector<vector<char>> G(N, K);
    auto solve = [&](auto &func, int n) -> void {
        do{
            bool ok = false;
            for(int i = 0; i < N; i++){
                if(G[n][i] == '.') continue;
                else if(G[n][i] == R[n]) ok = true;
                break;
            }
            if(!ok) continue;

            if(n > 0) func(func, n-1);

            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    if(G[i][j] == )
                }
            }

        }while(next_permutation(G[n].begin(), G[n].end()));
    };

    solve(solve, 4);
    return 0;
}