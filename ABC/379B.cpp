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
    int N,K; cin >> N >> K;
    string S; cin >> S;

    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(S[i] == 'O'){
            cnt++;
        }else{
            cnt = 0;
        }

        if(cnt >= K){
            ans++;
            cnt = 0;
        }
    }

    cout << ans << endl;
    return 0;
}