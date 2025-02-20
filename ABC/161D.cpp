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

vector<ll> lunlun(){
    vector<ll> ret;

    auto solve = [&](auto self, ll now, int limit) {
        ret.push_back(now);
        if(limit<0) return; 

        int sup = ( (now<10) ? now : now%10);
        if(isRange(sup+1, 0, 10)){
            self(self, now*10+sup+1, limit-1);
        }

        self(self, now*10+sup, limit-1);

        if(isRange(sup-1, 0, 10)){
            self(self, now*10+sup-1, limit-1);
        }
    };
    
    for(ll i = 1; i < 10; i++){
        solve(solve, i, 10);
    }


    sort(ALL(ret));
    return ret;
}

int main(){
    int K; cin >> K;

    auto A = lunlun();
    // cout << A.size() << endl;
    // for(auto &_v : A) cout << _v << " "; cout << endl;
    cout << A[K-1] << endl;
    return 0;
}