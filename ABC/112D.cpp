#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
struct Point{int x,y; Point(){}; Point(int _x, int _y):x(_x),y(_y){}};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    ll N,M; cin >> N >> M;
    if(N==1){
        cout << M << endl;
        return 0;
    }

    // 約数列挙
    vector<ll> div;
    for(ll i = 2; i*i <= M; i++){
        if(M%i != 0) continue;
        div.push_back(i);

        if(M/i != i) div.push_back(M/i);
    }
    div.push_back(1); // 番兵
    sort(ALL(div));
    // for(auto &_v : div) cout << _v << " "; cout << endl;

    // 公約数の上界はM/N
    cout << *prev(upper_bound(ALL(div), M/N)) << endl;
    return 0;
}