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
    int N; cin >> N;
    vector A(N, vector(N, vector<int>(N, 0)));
    for(auto &x : A){
        for(auto &y : x){
            for(auto &z : y){
                cin >> z;
            }
        }
    }

    vector csum(N+1, vector(N+1, vector<ll>(N+1, 0)));
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            for(int k = 1; k <= N; k++){
                csum[i][j][k] = A[i-1][j-1][k-1]
                    + csum[i-1][j][k] + csum[i][j-1][k] + csum[i][j][k-1]
                    - csum[i-1][j-1][k] - csum[i-1][j][k-1] - csum[i][j-1][k-1]
                    + csum[i-1][j-1][k-1];
            }
        }
    }

    // for(auto &_v : csum){ for(auto &_vv : _v) for(auto &_vvv : _vv) cout << _vvv << " "; cout << endl; cout << endl; }

    int Q; cin >> Q;
    while(Q--){
        int Lx,Rx,Ly,Ry,Lz,Rz;
        cin >> Lx >> Rx >> Ly >> Ry >> Lz >> Rz;

        cout << csum[Rx][Ry][Rz] 
            - csum[Lx-1][Ry][Rz] - csum[Rx][Ly-1][Rz] - csum[Rx][Ry][Lz-1]
            + csum[Lx-1][Ly-1][Rz] + csum[Lx-1][Ry][Lz-1] + csum[Rx][Ly-1][Lz-1]
            - csum[Lx-1][Ly-1][Lz-1] 
        << endl;
    }
    return 0;
}