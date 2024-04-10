#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

#include <atcoder/all>
using namespace atcoder;

int main(){
    int N; cin >> N;

    vector<vector<int>> G(N);
    for(int i = 0; i < N; i++){
        int u,v; cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> C(N);
    for(auto &_v : C) cin >> _v;

    auto d = [&](int a, int b){
        return 0;
    };

    auto f = [&](int x){
        ll ret = 0;
        for(int i = 0; i < N; i++){
            ret += C[i] * d(x,i);
        }
    };

    return 0;
}