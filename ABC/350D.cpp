#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

#include <atcoder/all>
using namespace atcoder;

int main(){
    int N,M; cin >> N >> M;
    vector<vector<int>> G(N);
    dsu d(N);
    for(int i = 0; i < M; i++){
        int a,b; cin >> a >> b;
        a--; b--;
        d.merge(a,b);

        G[a].push_back(b);
        G[b].push_back(a);
    }

    auto dg = d.groups();
    for(auto &v : G) sort(ALL(v));
    for(auto &v : dg) sort(ALL(v));


    // cout << "\n"; for(auto &_v : G){ for(auto &_vv : _v) cout << _vv << " "; cout << "\n"; } cout << "\n";
    // for(auto &_v : d.groups()){ for(auto &_vv : _v) cout << _vv << " "; cout << endl; }

    ll ans = 0;
    for(int i = 0; i < dg.size(); i++){
        ll len = dg[i].size();
        ans += (len-1 + 1)*(len-1) / 2; // n頂点の連結成分に対してsum(n-1, n-2, ... , 1)個の辺
    }

    cout << ans-M << endl;
    return 0;
}