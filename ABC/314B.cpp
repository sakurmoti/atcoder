#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    
    vector<vector<pair<int, int>>> B(40);
    for(int i = 0; i < N; i++){
        int C; cin >> C;
        for(int j = 0; j < C; j++){
            int c; cin >> c;
            B[c].push_back(make_pair(C, i+1)); //cに賭けた人がi+1, C個賭けた
        }
    }

    int X; cin >> X;
    sort(B[X].begin(), B[X].end());
    
    int K = B[X].size();
    if(K != 0){
        B[X].push_back(make_pair(100, -1));
        B[X].push_back(make_pair(101, -1)); //番兵
    }

    for(int i = 0; i < K; i++){
        if(B[X][i].first != B[X][i+1].first){
            K = i+1;
            break;
        }
    }

    cout << K << endl;
    for(int i = 0; i < K; i++){
        cout << B[X][i].second << " \n"[i == K-1];
    }

    return 0;
}