#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    ll A,B,C,D; cin >> A >> B >> C >> D;

    // A,B,C,D > 0 になるように平行移動
    ll X = C-A;
    ll Y = D-B;
    A = (A%4) + 4;
    B = (B%4) + 4;
    C = A + X;
    D = B + Y;

    auto f = [](ll x, ll y) {
        // 2x4を1単位として見たときの2倍した面積をメモ
        // area[a][b] := (0, a], (0, b]の2倍の面積
        vector<vector<ll>> area = {
            {0,0,0,0,0},
            {0,2,3,3,4},
            {0,3,6,7,8}
        };

        // s1 := 1単位の個数
        ll s1 = area[2][4] * (x/4) * (y/2);

        // s2 := 右の端数
        ll s2 = area[2][x%4] * (y/2);

        // s3 := 上の端数
        ll s3 = area[y%2][4] * (x/4);

        // s4 := 右上の端数
        ll s4 = area[y%2][x%4];

        return s1 + s2 + s3 + s4;
    };

    // printf("%d %d %d %d\n", A,B,C,D);
    // printf("%d %d %d %d\n", f(C,D), f(C, B), f(A, D), f(A, B));
    cout << f(C,D) - f(C, B) - f(A, D) + f(A, B) << endl;
    return 0;
}