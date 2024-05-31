#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N; cin >> N;
    vector<int> S(50,0),T(50,0),U(50,0);
    
    for(int i = 0; i < N; i++){
        int a; cin >> a;
        S[a%46]++;
    }

    for(int i = 0; i < N; i++){
        int b; cin >> b;
        T[b%46]++;
    }

    for(int i = 0; i < N; i++){
        int c; cin >> c;
        U[c%46]++;
    }

    return 0;
}