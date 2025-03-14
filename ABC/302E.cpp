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

int main(){
    int N,Q; cin >> N >> Q;

    vector<set<int>> st(N);
    int ans = N;
    while(Q--){
        int q; cin >> q;

        if(q==1){
            int u,v; cin >> u >> v;
            u--; v--;
            if(st[u].empty()) ans--;
            if(st[v].empty()) ans--;

            st[u].insert(v);
            st[v].insert(u);

        }else{
            int v; cin >> v;
            v--;
            for(auto u : st[v]){
                st[u].erase(v);
                if(st[u].empty()) ans++;
            }
            if(!st[v].empty()){
                st[v].clear();
                ans++;
            }

        }
        // cout << "\t";
        cout << ans << endl;
    }
    return 0;
}