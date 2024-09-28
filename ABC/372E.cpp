#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
struct Point{int x, y;};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

#include <atcoder/all>
using namespace atcoder;

struct myset{
    int n;
    vector<vector<int>> vertex;
    myset(int _n) : n(_n){
        vertex.assign(n, vector<int>(10, -1));
        for(int i = 0; i < n; i++){
            vertex[i][0] = i+1;
        }
    }

    // u,vをkにmerge
    void merge(int u, int v, int k){
        auto cp = vertex[u];
        for(auto vv : vertex[v]) cp.push_back(vv);
        sort(RALL(cp));
        cp.erase(unique(ALL(cp)), cp.end());

        for(int i = 0; i < min(10, (int)cp.size()); i++){
            vertex[k][i] = cp[i];
        }
    }

    void print(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 10; j++){
                if(vertex[i][j] == -1) continue;
                cout << vertex[i][j] << " ";
            }cout << endl;
        }
    }
};

int main(){
    int N,Q; cin >> N >> Q;

    dsu d(N);
    myset mst(N);
    while(Q--){
        int q; cin >> q;
        if(q==1){
            int u,v; cin >> u >> v;
            u--; v--;
            int ul = d.leader(u);
            int vl = d.leader(v);
            d.merge(u,v);
            int nl = d.leader(u);

            mst.merge(ul, vl, nl);

        }else{
            int v,k; cin >> v >> k;
            v--; k--;
            int vl = d.leader(v);

            // cout << "\t";
            cout << mst.vertex[vl][k] << endl;
        }

        // mst.print();
    }
    return 0;
}