#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M;
    cin >> N >> M;

    vector<vector<int>> G(N+1);
    for(int i = 0; i < M; i++){
        int A,B; //AはBより強い
        cin >> A >> B;
        G[B].push_back(A); //BからAに伸びる有向グラフを作る
    }

    //有効グラフがどの頂点から初めても一つに定まるならその人が最強
    //つまりそこから出る辺がない頂点が一つなら最強
    int ans = -1;
    bool multiple = false;
    for(int i = 1; i <= N; i++){
        int V = G[i].size();
        if(V == 0){
            if(ans < 0){
                ans = i;

            }else{
                multiple = true;

            }
        }
    }

    if(multiple) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}