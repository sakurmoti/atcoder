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
    int N,X,Y; cin >> N >> X >> Y;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    int M = 2e5;
    vector<int> g(M, -1);
    for(int i = 0; i < X; i++){
        g[i] = 0;
    }

    for(int i = X; i < M; i++){
        if(i-Y>=0){
            if( (g[i-Y]==0 && g[i-X]==1) || (g[i-Y]==1 && g[i-X]==0) ){
                g[i] = 2;
            }else if( (g[i-Y]==0 || g[i-X]==0) ){
                g[i] = 1;
            }else{
                g[i] = 0;
            }
        }else{
            if(g[i-X] == 0){
                g[i] = 1;
            }else{
                g[i] = 0;
            }
        }
    }

    int xorSum = 0;
    for(int i = 0; i < N; i++){
        xorSum ^= g[A[i]];
    }

    // for(int i = 0; i < 10; i++){
    //     printf("g[%d] = %d\n",i, g[i]);
    // }

    if(xorSum == 0) cout << "Second" << endl;
    else cout << "First" << endl;
    return 0;
}