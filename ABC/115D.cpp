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
    ll N,X; cin >> N >> X;

    vector<pair<ll, ll>> memo(60, make_pair(1, 1));
    for(int i = 0; i < N; i++){
        auto[l,p] = memo[i];
        memo[i+1] = make_pair(l*2+3, p*2+1);
    }
    
    auto f = [&](auto self, ll level, ll x) -> ll {
        auto[layer, patty] = memo[level-1];
        if(level == 0){
            if(x<=0) return 0;
            else return 1;
        }else if(x <= 1 + layer){
            return self(self, level-1, x-1);
        }else{
            return patty + 1 + self(self, level-1, x-2-layer);
        }
    };

    cout << f(f, N, X) << endl;
    return 0;
}