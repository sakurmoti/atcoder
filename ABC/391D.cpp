#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N,W; cin >> N >> W;

    vector<tuple<ll, ll, ll>> blocks(N);
    vector<vector<pair<ll, ll>>> G(W);
    for(int i = 0; i < N; i++){
        int x,y; cin >> x >> y;
        x--; y--;
        blocks[i] = make_tuple(y, x, i);
        G[x].push_back(make_pair(y, i));
    }

    for(int j = 0; j < W; j++){
        sort(ALL(G[j]));
    }

    vector<ll> ans(N, 1e18);
    ll elapsed = 0;
    for(int i = 0; i < N; i++){
        // i段目のブロック群がいつ消えるか
        ll maxi = -1;
        for(int j = 0; j < W; j++){
            if(!isRange(i, 0, (int)G[j].size())){
                maxi = -1;
                break;
            }
            auto [y, x, idx] = blocks[G[j][i].second];

            chmax(maxi, y-i+1+elapsed);
        }

        if(maxi < 0){
            break;
        }

        for(int j = 0; j < W; j++){
            auto [y, x, idx] = blocks[G[j][i].second];
            ans[idx] = maxi;
        }

        elapsed = maxi;
    }

    // for(auto &_v : ans) cout << _v << " "; cout << endl;

    int Q; cin >> Q;
    while(Q--){
        int t,a; cin >> t >> a;

        cerr << "\t";
        if(ans[a-1] > t){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}