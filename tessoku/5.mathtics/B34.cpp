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
    vector<ll> A(N);
    for(auto &_v : A) cin >> _v;

    // 観察からg = {0, 0, 1, 1, 2, / 0, 0, 1, 1, 2, / 0..}となっていることがわかるので
    ll xorSum = 0;
    for(int i = 0; i < N; i++){
        int grundy = -1;
        if(A[i]%5 == 0 || A[i]%5 == 1){
            grundy = 0;
        }else if(A[i]%5 == 2 || A[i]%5 == 3){
            grundy = 1;
        }else{
            grundy = 2;
        }

        xorSum ^= grundy;
    }

    if(xorSum == 0) cout << "Second" << endl;
    else cout << "First" << endl;
    return 0;
}