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
    string S,T; cin >> S >> T;

    if(S==T){
        cout << 0 << endl;
        return 0;
    }

    int N = S.size();
    int M = T.size();
    for(int i = 0; i < min(N,M); i++){
        if(S[i] != T[i]){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << min(N,M)+1 << endl;
    return 0;
}