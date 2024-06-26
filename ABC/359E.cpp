#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N; cin >> N;
    vector<ll> H(N);
    for(auto &_v : H) cin >> _v;

    vector<ll> ans(N+1, 0);
    stack<ll> wall;
    wall.push(0);

    ll now = 0;
    for(int i = 0; i < N; i++){
        while()
    }
    return 0;
}