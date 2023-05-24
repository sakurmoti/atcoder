#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;
using namespace atcoder;

int main(){
    int N,M;
    cin >> N >> M;

    vector<string> S(N);
    for(auto &v : S) cin >> v;

    dsu d(N);
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            int cnt = 0;
            for(int k = 0; k < M; k++){
                if(S[i][k] != S[j][k]){
                    cnt++;
                }
            }

            if(cnt == 1){
                d.merge(i,j);
            }
        }
    }

    vector<vector<int>> a = d.groups();
    /*for(auto v : a){
        for(auto u : v){
            cout << u << " ";
        }
        cout << endl;
    }*/

    if(a.size() == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}