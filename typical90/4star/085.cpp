#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    ll K; cin >> K;
    
    map<ll, int> factor;
    ll a = K;
    for(ll i = 2; i*i <= K; i++){
        while(a%i == 0){
            factor[i]++;
            a /= i;
        }
    }
    factor[a]++;
    factor[1] = 3;

    for(auto [k,v] : factor){
        printf("%d : %d\n", k, v);
    }
    return 0;
}