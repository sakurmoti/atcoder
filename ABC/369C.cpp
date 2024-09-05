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
    int N; cin >> N;
    vector<ll> A(N);
    for(auto &_v : A) cin >> _v;

    if(N==1){
        cout << 1 << endl;
        return 0;
    }

    vector<ll> B(N-1);
    for(int i = 0; i < N-1; i++){
        B[i] = A[i+1]-A[i];
    }

    // for(auto &_v : B) cout << _v << " "; cout << endl;
    
    vector<ll> C;
    int cnt = 1;
    for(int i = 1; i < N-1; i++){
        if(B[i] == B[i-1]){
            cnt++;
        }else{
            C.push_back(cnt);
            cnt = 1;
        }
    }
    C.push_back(cnt);
    
    // for(auto &_v : C) cout << _v << " "; cout << endl;
    
    ll ans = N;
    for(int i = 0; i < C.size(); i++){
        ans += (C[i] * (C[i]+1)) / 2;
    }

    cout << ans << endl;
    return 0;
}