#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    ll A,B; cin >> A >> B;

    ll G = gcd(A,B);
    // LCM = (A/G) * B
    // 1e18 > (A/G) * B
    
    if( ((ll)1e18/B) >= (A/G)){
        cout << lcm(A,B) << endl;
    }else{
        cout << "Large" << endl;
    }
    return 0;
}