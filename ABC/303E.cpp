#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &T, vector<int> &ans, vector<bool> &visited, int now){
    if(visited[now]) return;
    visited[now] = true;

    //星の中心の処理
    ans.push_back(T[now].size());
    for(int i = 0; i < T[now].size(); i++){
        int v = T[now][i];

        if(T[v].size() == 1){
            //中心が見つかったので隣接する端はもういらない
            visited[v] = true;
        
        }else{
            //中心に隣接する次数2の頂点が連結部分
            //頂点vのデータを消して切り離したことにする
            T[v].resize(0);
            visited[v] = true;

        }
    }
}

int main(){
    int N;
    cin >> N;

    vector<vector<int>> T(N+1);
    for(int i = 1; i <= N-1; i++){
        int u,v;
        cin >> u >> v;
    
        T[u].push_back(v);
        T[v].push_back(u);
    }

    vector<int> ans;
    vector<bool> visited(N+1, false);
    for(int i = 1; i <= N; i++){
        //cout << T[i].size() << " ";
        if(T[i].size() == 1){
            solve(T, ans, visited, T[i][0]);
        }
    }

    sort(ans.begin(), ans.end());
    for(auto v : ans){
        cout << v << " ";
    }
    return 0;
}