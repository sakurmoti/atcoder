#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

map<ll, ll> memo;
ll solve(ll x){
    if(memo.contains(x)) return memo[x];
    if(x == 0) return memo[0] = 0;
    if(x == 1) return memo[1] = 0;

    ll cost = solve(x/2) + solve(x/2 + x%2) + x;
    memo[x] = cost;
    return cost;
}

int main(){
    ll N; cin >> N;
    cout << solve(N) << endl;
    return 0;
}