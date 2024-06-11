#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

#include <atcoder/all>
using namespace atcoder;

int main(){
    int N; cin >> N;
    vector<int> A(N);
    for(auto &_v : A){
        cin >> _v;
        _v--;
    }
    
    dsu d(N);
    for(int i = 0; i < N; i++){
        d.merge(i, A[i]);
    }

    for(auto v : d.groups()){
        for(auto u : v){
            cout << u << " ";
        }
        cout << endl;
    }
    return 0;
}