#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

#include <atcoder/all>
using namespace atcoder;

int main(){
    int N,M; cin >> N >> M;

    // 頂点倍化union findで二部グラフ判定
    dsu d(2*N);

    vector<int> A(M),B(M);
    for(auto &_v : A) cin >> _v;
    for(auto &_v : B) cin >> _v;

    for(int i = 0; i < M; i++){
        int u = A[i];
        int v = B[i];
        u--; v--;

        d.merge(u, v+N);
        d.merge(u+N, v);
    }

    for(int i = 0; i < N; i++){
        if(d.same(i, i+N)){
            cout << "No" << endl;
            return 0;
        }

        cout << endl;
    }

    cout << "Yes" << endl;
    return 0;
}