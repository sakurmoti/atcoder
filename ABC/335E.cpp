#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,M; cin >> N >> M;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int u,v; cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    queue<int> que;
    vector<bool> decided(N, false);
    vector<int> score(N, -1e9); // 頂点1からiまで辿ったときのスコアの最大値
    score[0] = 1;
    decided[0] = true;
    que.push(0);
    bool prev = true;
    while(!que.empty()){
        int now = que.front();
        que.pop();

        if(now != 0 && decided[now]) continue;

        for(int i = 0; i < G[now].size(); i++){
            int next = G[now][i];
            // printf("A[now]=%d, A[next]=%d\n", A[now], A[next]);
            if(A[now] <= A[next]){
                if(score[next] < score[now] + (A[now] != A[next])){
                    score[next] = score[now] + (A[now] != A[next]);
                }

            }

            que.push(next);
        }

        if(prev) decided[now] = true;
        prev = decided[now];

    }

    // for(int _i = 0; _i < score.size(); _i++){
    //     cout << score[_i] << " \n"[_i == score.size()-1];
    // }

    if(score[N-1] < 0){
        cout << 0 << endl;
    }else{
        cout << score[N-1] << endl;
    }
    return 0;
}