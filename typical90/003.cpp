#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;

    // N頂点N-1辺なのでサイクルは存在しない
    // さらに連結グラフなのでこれは木構造
    vector<vector<int>> G(N);
    for(int i = 0; i < N-1; i++){
        int a,b;
        cin >> a >> b;

        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 木の直径となる2頂点を探し、その間に辺を追加するのが最適
    // ただ、全ての頂点からbfsでパスの最大を探すとO(N^2)
    // ここで、適当な頂点から最も遠い頂点vを探し、頂点vから最も遠い頂点uを探せば
    // u-v間が木の直径になることを利用 O(N)

    auto bfs = [&](int v) -> vector<int> {
        queue<int> que;
        que.push(v);
        vector<int> L(N, 1e9);
        L[v] = 0;
        while(!que.empty()){
            int now = que.front();
            que.pop();
            // printf("\tnow=%d\n", now);

            for(int i = 0; i < G[now].size(); i++){
                int next = G[now][i];
                // printf("next=%d\n", next);
                
                if(L[next] > L[now] + 1) que.push(next);
                L[next] = min(L[next], L[now] + 1);
            }
        }

        return L;
    };

    vector<int> L;
    int u, M=-1;

    // 頂点0から最も遠い頂点を探す
    L = bfs(0);
    // for(int _i = 0; _i < L.size(); _i++){
    //     cout << L[_i] << " \n"[_i == L.size()-1];
    // }

    for(int i = 0; i < N; i++){
        if(M < L[i]){
            u = i;
            M = L[i];
        }
    }
    
    // 頂点uから最も遠い頂点を探し、その距離を計算
    L = bfs(u);
    M = -1;
    for(int i = 0; i < N; i++){
        if(M < L[i]){
            M = L[i];
        }
    }

    cout << M+1 << endl;
    return 0;
}