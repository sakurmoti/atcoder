#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N,K,X; cin >> N >> K >> X;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    A.insert(A.begin() + K, X);
    for(auto &_v : A) cout << _v << " "; cout << endl;
    return 0;
}