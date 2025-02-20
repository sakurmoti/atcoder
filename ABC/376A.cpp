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
    int N,C; cin >> N >> C;
    vector<int> T(N+1, -1e8);
    for(int i = 1; i <= N; i++){
        cin >> T[i];
    }

    int time = 0;
    int idx = 1;
    int cnt = 0;
    int last = 0;
    while(time < 1e6){
        if(idx <= N && time == T[idx]){
            if( (T[idx] - T[last]) >= C){
                cnt++;
                last = idx;

                // cout << idx << endl;
            }
            idx++;
        }

        time++;
    }

    cout << cnt << endl;
    return 0;
}