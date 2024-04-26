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
    vector<vector<int>> X(H+1, vector<int>(W+1));
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            cin >> X[i][j];
        }
    }

    vector<vector<int>> csum(H+1, vector<int>(W+1, 0));
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            csum[i][j] = csum[i][j-1] + X[i][j];
        }
    }

    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            csum[i][j] += csum[i-1][j];
        }
    }

    // cout << "\n"; for(auto &_v : csum){ for(auto &_vv : _v) cout << _vv << " "; cout << endl; } cout << "\n";


    int Q; cin >> Q;
    while(Q--){
        int A,B,C,D; cin >> A >> B >> C >> D;

        cout << csum[C][D] - csum[A-1][D] - csum[C][B-1] + csum[A-1][B-1] << endl;
    }
    return 0;
}