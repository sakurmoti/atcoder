#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int H,W; cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W)), B(H, vector<int>(W));
    for(auto &_v : A) for(auto &_vv : _v) cin >> _vv;
    for(auto &_v : B) for(auto &_vv : _v) cin >> _vv;

    ll ans = 0;
    for(int i = 0; i < H-1; i++){
        for(int j = 0; j < W-1; j++){
            int d = (B[i][j] - A[i][j]);
            ans += abs(d);
            A[i][j] += d;
            A[i][j+1] += d;
            A[i+1][j] += d;
            A[i+1][j+1] += d;
        }
    }

    bool ok = true;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(A[i][j] != B[i][j]) ok = false;
        }
    }

    // for(auto &_v : A){ for(auto &_vv : _v) cout << _vv << " "; cout << endl; }

    if(ok){
        cout << "Yes" << endl;
        cout << ans << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}