#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N,T,P;
    cin >> N >> T >> P;

    vector<int> L(N);
    for(auto &_v : L) cin >> _v;

    for(int d = 0; d < 1000; d++){
        int cnt = 0;
        for(int i = 0; i < N; i++){
            if(L[i] >= T) cnt++;
            L[i]++;
        }

        if(cnt >= P){
            cout << d << endl;
            return 0;
        }
    }
    return 0;
}