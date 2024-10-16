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
    int N; cin >> N;
    vector<ll> H(N);
    for(auto &_v : H) cin >> _v;

    vector<ll> ans(N+1, 0);
    // pque(u,v) := 壁の高さu, インデックスをv
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
    ll time = 0;
    for(int i = 0; i < N; i++){
        pque.push(make_pair(H[i], i+1));
        while(!pque.empty()){
            auto[h,idx] = pque.top();
            pque.pop();
        }

    }
    return 0;
}