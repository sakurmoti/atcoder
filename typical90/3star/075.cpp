#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

vector<ll> factorize(ll x){
    vector<ll> p;
    ll cp = x;
    for(ll i = 2; i*i <= x; i++){
        while(cp % i == 0){
            cp /= i;
            p.push_back(i);
        }
    }

    if(cp != 1) p.push_back(cp);
    return p;
}

int main(){
    ll N; cin >> N;

    auto prime = factorize(N);
    // for(auto v : prime) cout << v << " "; cout << endl;

    ll len = prime.size();
    ll buf = 1;
    ll ans = 0;
    while(buf < len){
        buf *= 2;
        ans++;
    }

    cout << ans << endl;
    return 0;
}