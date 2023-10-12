#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

int main(){
    ll N; cin >> N;

    // x = {1, 10, 100, 1000...}のとき f(x) = 1
    // y = x+1とするとf(y) = f(x) + 1

    auto SUM = [](mint n) -> mint {
        // 等差1, 項数nの総和を返す
        return (n*(n+1)/2);
    };

    ll l = 1;
    unsigned long long r = 10;
    mint ans = 0;
    while(r <= N){
        // [l, r)
        ans += SUM(mint(r-l));
        l *= 10;
        r *= 10;
        // printf("ans = %d\n", ans.val());
    }

    // [l, N]
    ans += SUM(mint(N-l+1));
    cout << ans.val() << endl;
    return 0;
}