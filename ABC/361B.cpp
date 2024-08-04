#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    vector<int> A(6),B(6);
    for(auto &_v : A) cin >> _v;
    for(auto &_v : B) cin >> _v;

    bool flag = true;
    for(int i = 0; i < 3; i++){
        if( ! ( (A[i] < B[i+3] && A[i+3] > B[i]) )) flag = false;
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}