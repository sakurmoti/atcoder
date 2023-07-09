#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M;
    cin >> N >> M;

    vector<vector<int>> child(N+1);
    for(int i = 2; i <= N; i++){
        int p; cin >> p;
        child[p].push_back(i);
    }

    vector<vector<int>> sum(N+1);
    for(int i = 1; i <= N; i++){
        sum[i] = child[i].size();
    }

    vector<int> ins(N+1, -1);
    for(int i = 0; i < M; i++){
        int x,y; cin >> x >> y;
        ins[x] = max(ins[x],y); //最大値の保険だけ見ればよい
    }

    for(int i = 1; i <= N; i++){
        if(ins[x] > 0){
            add.insert(x); //x自身も保険に加入
        }
    }
    return 0;
}