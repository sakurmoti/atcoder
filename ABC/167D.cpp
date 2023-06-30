#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N,K;
vector<vector<int>> G;
set<int> topological(vector<int> &indeg){
    set<int> ret;

    queue<int> que; //入次数が0の頂点
    for(int i = 0; i < N; i++){
        if(indeg[i] == 0) que.push(i);
    }

    while(!que.empty()){
        int v = que.front();
        que.pop();

        //入次数が0の頂点と隣接している頂点の入次数を減らす
        for(int i = 0; i < G[v].size(); i++){
            int u = G[v][i];
            indeg[u]--;
            if(indeg[u] == 0) que.push(u);
        }

        //頂点vをソート済み
        ret.insert(v);
    }

    return ret;
}

int main(){
    cin >> N >> K;

    G.resize(N);
    vector<int> indeg(N,0);
    for(int i = 0; i < N; i++){
        int a; cin >> a;
        a--;
        G[i].push_back(a);
        indeg[a]++; //頂点頂点iからaへのグラフなのでaの入次数を1増やす
    }

    set<int> sorted = topological(indeg);

    
    //閉路は今回必ずできる
    //閉路に含まれていない頂点がsortedに入る
    for(auto &v : sorted) cout << v << ' ';

    for(int i = 0; i < N; i++){
        //空ならその頂点が閉路の始まり
        if(sorted.empty()){
            
        }
    }


    return 0;
}