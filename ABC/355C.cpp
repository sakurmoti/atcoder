#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N,T; cin >> N >> T;
    vector<vector<int>> A(N, vector<int>(N, 1e9));
    for(int i = 1; i <= T; i++){
        int a; cin >> a;
        a--;
        A[a/N][a%N] = i;
    }

    int ans = 1e9;
    for(int i = 0; i < N; i++){
        int m = -1;
        for(int j = 0; j < N; j++){
            chmax(m, A[i][j]);
        }

        chmin(ans, m);
    }

    for(int j = 0; j < N; j++){
        int m = -1;
        for(int i = 0; i < N; i++){
            chmax(m, A[i][j]);
        }

        chmin(ans, m);
    }

    int m = -1;
    for(int i = 0; i < N; i++){
        chmax(m, A[i][i]);
    }
    chmin(ans, m);

    m = -1;
    for(int i = 0; i < N; i++){
        chmax(m, A[i][N-1-i]);
    }
    chmin(ans, m);

    if(ans > 1e8) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}