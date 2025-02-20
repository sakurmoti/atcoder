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
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    int ans = 0;
    int r = 0;
    vector<bool> used(N+1, false);
    for(int l = 0; l < N; l+=2){ // 開始位置が偶数の場合
        chmax(r, l); // 常にrはl以上になるように

        while(r+1 < N && A[r] == A[r+1] && !used[A[r]]){
            used[A[r]] = true;
            r+=2;
        }

        // printf("l:%d r:%d\n", l, r);
        chmax(ans, r-l);

        used[A[l]] = false;
    }

    // printf("----\n");

    r = 0;
    used.assign(N+1, false);
    for(int l = 1; l < N; l+=2){ // 開始位置が奇数の場合
        chmax(r, l);

        while(r+1 < N && A[r] == A[r+1] && !used[A[r]]){
            used[A[r]] = true;
            r+=2;
        }

        // printf("l:%d r:%d\n", l, r);
        chmax(ans, r-l);

        used[A[l]] = false;
    }

    cout << ans << endl;
    return 0;
}