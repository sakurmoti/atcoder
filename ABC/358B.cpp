#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N,A; cin >> N >> A;
    vector<int> T(N);
    for(auto &_v : T) cin >> _v;

    int now = 0;
    for(int i = 0; i < N; i++){
        if(now < T[i]){
            now = T[i];
        }
        now += A;

        cout << now << endl;
    }
    return 0;
}