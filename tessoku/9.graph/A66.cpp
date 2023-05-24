#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

int main(){
    int N,Q;
    cin >> N >> Q;

    dsu Graph(N);
    for(int i = 0; i < Q; i++){
        int cmd,u,v;
        cin >> cmd >> u >> v;

        u--;
        v--;
        if(cmd == 1){
            Graph.merge(u,v);

        }else{
            bool flag = Graph.same(u,v);
            if(flag) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}