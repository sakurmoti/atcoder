#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    vector<string> S(N);
    for(auto &_v : S) cin >> _v;

    vector<vector<int>> ans(1000);
    for(int i = 0; i < N; i++){
        int cnt = 0;
        for(int j = 0; j < N; j++){
            if(S[i][j] == 'o') cnt++;
        }
        ans.at(cnt).push_back(i+1);
    }

    for(int i = 200; i >= 0; i--){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
    }
    return 0;
}