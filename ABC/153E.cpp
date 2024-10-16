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
    int H,N; cin >> H >> N;
    vector<int> A(N),B(N);
    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i];
    }

    vector<int> dp(H+1, 1e9);
    dp[0] = 0;
    for(int i = 0; i < N; i++){
        for(int h = 0; h <= H; h++){
            chmin(dp[min(h+A[i], H)], dp[h] + B[i]);
        }
    }

    cout << dp[H] << endl;
    return 0;
}