#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;

    int dx = (tx-sx);
    int dy = (ty-sy);

    // 1 : 右いって上
    cout << string(dx, 'R') << string(dy, 'U');
    cerr << '\n';

    // 2 : 左いって下
    cout << string(dx, 'L') << string(dy, 'D');
    cerr << '\n';

    // 3 : 下から出て右いって右から入る
    cout << 'D';
    cout << string(dx+1, 'R') << string(dy+1, 'U');
    cout << 'L';
    cerr << '\n';

    // 4 : 上から出て左いって左から入る
    cout << 'U';
    cout << string(dx+1, 'L') << string(dy+1, 'D');
    cout << 'R';
    return 0;
}