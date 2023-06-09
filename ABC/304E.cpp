#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;
using namespace atcoder;

int main(){
    int N,M;
    cin >> N >> M;

    dsu d(N+1);
    for(int i = 0; i < M; i++){
        int u,v;
        cin >> u >> v;

        d.merge(u,v);
    }

    set<pair<int, int>> noPaths;
    int K; cin >> K;
    for(int i = 0; i < K; i++){
        int x,y;
        cin >> x >> y;

        int u = d.leader(x);
        int v = d.leader(y);
        noPaths.insert(make_pair(u,v));
        noPaths.insert(make_pair(v,u));
    }

    int Q; cin >> Q;
    for(int q = 0; q < Q; q++){
        int x,y;
        cin >> x >> y;

        int u = d.leader(x);
        int v = d.leader(y);

        if(noPaths.find(make_pair(u,v)) != noPaths.end() || noPaths.find(make_pair(v,u)) != noPaths.end()){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }


    return 0;
}