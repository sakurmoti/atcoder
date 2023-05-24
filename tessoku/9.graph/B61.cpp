#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    vector<vector<int>> G(N+1);
    for(int i = 0; i < M; i++){
        int a,b;
        cin >> a >> b;

        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }

    int ans = 0;
    int maximum = -1;
    for(int i = 1; i <= N; i++){
        if(maximum < (int)G.at(i).size()){
            maximum = G.at(i).size();
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}