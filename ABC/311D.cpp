#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M;
    cin >> N >> M;

    vector<vector<char>> S(N+1, vector<char>(M+1));
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> S[i][j];
        }
    }
    
    queue<pair<int, int>> next;
    next.push(make_pair(2,2));

    int dx[] = {0,1,0,-1};
    int dy[] = {1,0,-1,0};
    vector<vector<bool>> visited(N+1, vector<bool>(M+1, false));
    vector<vector<bool>> stopped(N+1, vector<bool>(M+1, false));
    visited[2][2] = true;
    stopped[2][2] = true;

    while(!next.empty()){
        pair<int, int> v = next.front();
        next.pop();
        // printf("------now-------  X=%d, Y=%d\n",v.first, v.second);

        for(int i = 0; i < 4; i++){
            int X = v.first;
            int Y = v.second;
            visited[Y][X] = true;
            while(S[Y+dy[i]][X+dx[i]] == '.'){
                X += dx[i];
                Y += dy[i];
                visited[Y][X] = true;
                // printf("X=%d, Y=%d\n",X,Y);
            }

            //最後のX,Yは壁の手前
            if(!stopped[Y][X]){
                // printf("next = (%d, %d)\n", X,Y);
                next.push(make_pair(X,Y)); //まだ未探索ならpush
                stopped[Y][X] = true;
            }

        }
        
    }

    int cnt = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(visited[i][j]){
                cnt++;
                // printf("i=%d, j=%d\n",i,j);
            }
        }
    }

    cout << cnt << endl;
    return 0;
}