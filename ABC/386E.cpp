#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
struct Point{int x,y; Point(){}; Point(int _x, int _y):x(_x),y(_y){}};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    ll N,K; cin >> N >> K;
    vector<ll> A(N);
    for(auto &_v : A) cin >> _v;

    ll ans = -1;
    auto dfs = [&](auto self, ll idx, ll depth, ll xsum) -> void {
        if(depth == K){
            chmax(ans, xsum);
            return;
        }

        for(int i = idx; i < N; i++){
            self(self, i+1, depth+1, xsum xor A[i]);
        }
    };

    for(int i = 0; i < N; i++){
        dfs(dfs, i, 1, A[i]);
    }

    cout << ans << endl;

    aabcbbcd
    aabcbcd
    return 0;
}