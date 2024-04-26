#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N,Q; cin >> N >> Q;
    vector<bool> tooth(N, true);

    while(Q--){
        int T; cin >> T;
        T--;

        tooth[T] = !tooth[T];
    }

    int ans = 0;
    for(auto u : tooth) if(u) ans++;
    cout << ans << endl;
    return 0;
}