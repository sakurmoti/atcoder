#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M;
    cin >> N >> M;
    string S; cin >> S;
    vector<int> C(N);
    for(auto &_v : C) cin >> _v;

    vector<vector<int>> idx(M+1);
    for(int i = 0; i < N; i++){
        int color = C[i];
        idx[color].push_back(i); //i文字目の色の情報
    }

    vector<char> ans(N);
    //O(N+M)
    for(int c = 0; c <= M; c++){
        int K = idx[c].size();
        for(int i = 0; i < K; i++){
            int next_index = idx[c][(i+1)%K];
            int prev_char = S[idx[c][i]];

            ans[next_index] = prev_char;
        }
    }

    for(int i = 0; i < N; i++){
        cout << ans[i];
    }
    cout << endl;
    return 0;
}