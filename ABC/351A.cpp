#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    vector<int> A(9);
    vector<int> B(8);
    for(auto &_v : A) cin >> _v;
    for(auto &_v : B) cin >> _v;

    int a = 0;
    for(auto v : A) a += v;
    int b = 0;
    for(auto v : B) b += v;

    cout << a - b+1 << endl;
    return 0;
}