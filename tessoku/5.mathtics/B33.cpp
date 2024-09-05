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
    int N,H,W; cin >> N >> H >> W;
    vector<int> A(N),B(N);
    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i];
        
        // A[i]行目にあるときA[i]-1回操作できる
        A[i]--;
        B[i]--;
    }

    // 全ての駒を(0,0)にしたら勝ち
    // 行と列は独立に考えていい
    // A1, A2 .. B1, B2 .. Bnの2N個の山のnim
    int xorSum = 0;
    for(int i = 0; i < N; i++){
        xorSum ^= A[i];
        xorSum ^= B[i];
    }

    if(xorSum==0) cout << "Second\n";
    else cout << "First\n";
    return 0;
}