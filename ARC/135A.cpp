#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

map<ll, ll> memo;
ll f(ll x){
    if(memo.find(x) != memo.end()) return memo[x];
    auto &m = memo[x];
    if(x <= 4) return (m = x);

    mint now(x);
    mint next(f(x/2) * f((x+1)/2) );
    return (m = next.val());
}

int main(){
    ll X; cin >> X;

    // x < f(x) = floor(x/2) * ceil(x/2)の限り操作したい
    // x>4のとき常にf(x)が大きい
    cout << f(X) << endl;
    return 0;
}