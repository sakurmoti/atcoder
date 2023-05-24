#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int s,t,Q;
int buf = 1e7;
int N,K;
vector<int> minEdge; //sからの最短経路
vector<vector<int>> A;

void dfs(int now){
    for(int u = 0; u < N; u++){
        int flag = A.at(now).at(u);

        if(flag == 1){
            if(minEdge.at(now) + 1 < minEdge.at(u)){
                minEdge.at(u) = minEdge.at(now) + 1;
            
            }else if(s==t && u==t){
                if(minEdge.at(now) + 1 < buf) buf = minEdge.at(now) + 1;
            }

        }
    }

    for(int u = 0; u < N; u++){
        if(A.at(now).at(u) == 1) dfs(u);
    }
}

int main(){
    cin >> N >> K;

    A.resize(N, vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> A.at(i).at(j);
        }
    }

    cin >> Q;

    //mod(N)をとった頂点と同じという仮説
    for(int q = 0; q < Q; q++){
        cin >> s >> t;
        s--; t--; //0-idx
        s %= N; t %= N; //mod N

        minEdge.assign(N,1e7);
        minEdge.at(s) = 0;
        buf = 1e7;
        
        dfs(s);

        /*for(auto v : minEdge){
            cout << v << " ";
        }cout << endl;*/

        int ans = minEdge.at(t);
        if(1e5 < ans){
            cout << -1 << endl;
            
        }else if(ans == 0){
            cout << buf << endl;
        
        }else{
            cout << ans << endl;
        }
        
    }

    return 0;
}