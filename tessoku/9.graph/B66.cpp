#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int N,M;
    cin >> N >> M;

    vector<int> A(M+1),B(M+1);
    dsu d(N+1);
    for(int i = 1; i <= M; i++){
        cin >> A.at(i) >> B.at(i);
    }

    int Q;
    cin >> Q;
    vector<int> cmd(Q), buf;
    vector<pair<int, int>> opr(Q);
    for(int i = 0; i < Q; i++){
        cin >> cmd.at(i);
        if(cmd.at(i) == 1){
            int x;
            cin >> x;
            opr.at(i) = make_pair(x,-1);
            buf.push_back(x);
        
        }else{
            int u,v;
            cin >> u >> v;
            opr.at(i) = make_pair(u,v);

        }
    }

    //クエリを逆順に答える
    //まずは最後の状態のグラフをつくる
    vector<bool> connect(M+1, true);
    for(auto v : buf){
        connect.at(v) = false;
    }

    for(int i = 1; i <= M; i++){
        if(connect.at(i)) d.merge(A.at(i), B.at(i));
    }

    //グラフが出来たので逆順にクエリに答える
    //クエリ1が与えられたらA.at(x)とB.at(x)を連結すればよい
    vector<string> ans;
    for(int i = Q-1; i >= 0; i--){
        if(cmd.at(i) == 1){
            int x = opr.at(i).first;
            d.merge(A.at(x),B.at(x));
        
        }else{
            int u = opr.at(i).first;
            int v = opr.at(i).second;
            ans.push_back((d.same(u,v) ? "Yes" : "No"));

        }
    }

    reverse(ans.begin(), ans.end());
    for(auto v : ans) cout << v << endl;
    return 0;
}