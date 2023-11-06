#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

#include <atcoder/all>
using namespace atcoder;

int main(){
    int N,M; cin >> N >> M;
    vector<int> A(M), B(M);
    for(auto &_v : A) cin >> _v;
    for(auto &_v : B) cin >> _v;

    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int a = A[i]-1;
        int b = B[i]-1;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    // このグラフが二部グラフであれば、0,1の集合に分けられる
    vector<int> X(N, -1);
    bool ans = true;

    auto dfs = [&](int now) -> void {
        stack<pair<int, int>> st;
        st.push(make_pair(now, 0));

        while(!st.empty()){
            pair<int, int> A = st.top();
            st.pop();
            int v = A.first;
            int m = A.second xor 1;

            for(int i = 0; i < G[v].size(); i++){
                int nex = G[v][i];
                if(X[nex] == -1){
                    X[nex] = m;
                    st.push(make_pair(nex, m));
                }else if(X[nex] != m){
                    ans = false;
                }
            }
        }
    };

    for(int i = 0; i < N; i++){
        if(X[i] == -1){
            dfs(i);
        }
    }

    // for(auto &_v : X) cout << _v << ' ';

    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}