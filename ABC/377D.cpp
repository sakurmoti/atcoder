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

#include <atcoder/all>
using namespace atcoder;
using S = int;
S op(S a, S b){return min(a,b);}
int elem;
S e(){return elem;}

int main(){
    int N,M; cin >> N >> M;
    vector<pair<int, int>> I(N);
    for(int i = 0; i < N; i++){
        cin >> I[i].first >> I[i].second;
    }

    sort(ALL(I));

    elem = M+1;
    segtree<S, op, e> seg(M+1);
    for(int i = 0; i < N; i++){
        // 区間の始まりが同じものが複数あるなら、終わりが最小のものを採用する
        if(seg.get(I[i].first) < I[i].second) continue;
        seg.set(I[i].first, I[i].second);
    }

    ll ans = 0;
    for(int l = 1; l <= M; l++){
        int r = seg.prod(l, M+1);

        ans += (r-1)-l+1;
        // printf("[l,r) = [%d, %d)\n",l,r);
    }

    cout << ans << endl;
    return 0;
}