#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int A,B; cin >> A >> B;

    if(A==B){
        cout << -1 << endl;
    }else{
        int ans = 1;
        while(ans == A || ans == B){
            ans++;
        }

        cout << ans << endl;
    }
    return 0;
}