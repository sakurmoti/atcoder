#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int N,M;
    cin >> N >> M;

    dsu d(N);
    vector<int> edge(N, 0);
    for(int i = 0; i < M; i++){
        int u,v;
        cin >> u >> v;

        //0-idx
        u--; v--;
        
        int buf1 = d.leader(u);
        int buf2 = d.leader(v);
        bool flag = d.same(u,v);

        d.merge(u,v);
        
        if(flag) edge[d.leader(u)] += 1;
        else edge[d.leader(u)] = edge[buf1] + edge[buf2] + 1;
    }

    for(int v = 0; v < N; v++){
        //cout << d.leader(v) << " " << d.size(v) << " " << edge[d.leader(v)] << endl;
        if(d.size(v) == edge[d.leader(v)]){
            continue;
        
        }else{
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}