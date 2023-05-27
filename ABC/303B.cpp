#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    vector<vector<int>> A(M,vector<int>(N));
    for(auto &v : A){
        for(auto &x : v){
            cin >> x;
        }
    }

    vector<vector<bool>> nofriend(N+1, vector<bool>(N+1,true));
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N-1; j++){
            int now = A[i][j];
            int next = A[i][j+1];

            nofriend.at(now).at(next) = false;
            nofriend.at(next).at(now) = false;
        }
    }

    int ans = 0;
    for(int i = 1; i <= N; i++){
        for(int j = i+1; j <= N; j++){
            if(nofriend[i][j]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}