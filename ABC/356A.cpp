#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N,L,R; cin >> N >> L >> R;

    vector<int> A(N,0);
    iota(ALL(A), 1);
    
    L--;
    R--;
    reverse(A.begin()+L, A.begin()+R+1);

    for(auto &_v : A) cout << _v << " "; cout << endl;
    return 0;
}