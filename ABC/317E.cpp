#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int H,W;
vector<vector<char>> A;
vector<vector<bool>> visited;

int main(){
    cin >> H >> W;
    A.resize(H+2, vector<char>(W+2, '#'));
    visited.resize(H+2, vector<bool>(W+2, false));

    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            cin >> A[i][j];
        }
    }

    pair<int, int> st,gl;
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            char c = A[i][j];

            if(c == 'S'){
                st = make_pair(i,j);
            }

            if(c == 'G'){
                gl = make_pair(i,j);
            }

             if(c == '>'){
                for(int k = j+1; k <= W; k++){
                    if(A[i][k] == '.' || A[i][k] == '!'){
                        A[i][k] = '!';
                    }else{
                        break;
                    }
                }
            }

            if(c == 'v'){
                for(int k = i+1; k <= H; k++){
                    if(A[k][j] == '.' || A[k][j] == '!'){
                        A[k][j] = '!';
                    }else{
                        break;
                    }
                }
            }

            if(c == '<'){
                for(int k = j-1; k >= 1; k--){
                    if(A[i][k] == '.' || A[i][k] == '!'){
                        A[i][k] = '!';
                    }else{
                        break;
                    }
                }
            }

            if(c == '^'){
                for(int k = i-1; k >= 1; k--){
                    if(A[k][j] == '.' || A[k][j] == '!'){
                        A[k][j] = '!';
                    }else{
                        break;
                    }
                }
            }
        }
    }

    // for(auto v : A){
    //     for(auto u : v){
    //         cout << u;
    //     }
    //     cout << endl;
    // }

    vector<vector<int>> dist(H+2, vector<int>(W+2, -1));
    queue<pair<int, int>> que;
    que.push(st);
    dist[st.first][st.second] = 0;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    while(!que.empty()){
        pair<int, int> v = que.front();
        que.pop();

        for(int i = 0; i < 4; i++){
            pair<int, int> next = make_pair(v.first + dy[i], v.second + dx[i]);
            
            //探索済み
            int d = dist.at(next.first).at(next.second);
            if(d != -1) continue;

            //遷移不可
            char c = A.at(next.first).at(next.second);
            if( !(c == '.' || c == 'G') ) continue;

            dist[next.first][next.second] = dist[v.first][v.second] + 1;
            que.push(next);
        }
    }

    cout << dist[gl.first][gl.second] << endl;
    return 0;
}