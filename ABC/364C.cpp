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
    ll N,X,Y; cin >> N >> X >> Y;
    vector<ll> A(N),B(N);
    for(auto &_v : A) cin >> _v;
    for(auto &_v : B) cin >> _v;

    sort(RALL(A));
    sort(RALL(B));

    ll sweet=0, solty=0;
    for(int i = 0; i < N; i++){
        sweet += A[i];
        solty += B[i];

        if(sweet > X || solty > Y){
            cout << i+1 << endl;
            return 0;
        }
    }

    cout << N << endl;
    return 0;
}