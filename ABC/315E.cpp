#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
vector<vector<int>> P;
vector<bool> isRead;
queue<int> que;
void dfs(int v){
    for(int i = 0; i < P[v].size(); i++){
        int book = P[v][i];
        if(isRead[book]){
            continue;
        }

        //読んだことがなければ先にそれを読む
        dfs(book);

    }

    que.push(v);
    isRead[v] = true;
}

int main(){
    cin >> N;
    P.resize(N+1);
    isRead.resize(N+1, false);
    for(int i = 1; i <= N; i++){
        int c; cin >> c;
        P[i].resize(c);
        for(int j = 0; j < c; j++){
            cin >> P[i][j];
        }
    }

    //1の本を読むために2の本読むために...とつなげる深さ優先探索
    dfs(1);

    while(!que.empty()){
        int b = que.front();
        que.pop();

        if(b == 1){
            cout << endl;
        }else{
            cout << b << " ";
        }

    }
    return 0;
}