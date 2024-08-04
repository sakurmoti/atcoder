#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int R; cin >> R;

    if(R < 100){
        cout << 100-R << endl;
    }else if(R < 200){
        cout << 200-R << endl;
    }else if(R < 300){
        cout << 300-R << endl;
    }else if(R < 400){
        cout << 400-R << endl;
    }
    return 0;
}