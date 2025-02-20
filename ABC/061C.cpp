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
    ll N,K; cin >> N >> K;
    
    vector<pair<int, int>> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i].first >> A[i].second;
    }

    sort(ALL(A));

    ll now = 0;
    for(int i = 0; i < N; i++){
        now += A[i].second;

        if(now >= K){
            cout << A[i].first << endl;
            return 0;
        }
    }
    return 0;
}