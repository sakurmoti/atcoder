#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int Y; cin >> Y;
    if(Y%4!=0){
        cout << 365 << endl;
        return 0;
    }
    if(Y%4==0 && Y%100 != 0){
        cout << 366 << endl;
        return 0;
    }

    if(Y%100==0 && Y%400!=0){
        cout << 365 << endl;
        return 0;
    }

    cout << 366 << endl;
    return 0;
}