#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    ll A,M,L,R;
    cin >> A >> M >> L >> R;

    /*
    次の条件を満たす整数kの個数を数える
    L <= A + k*M <= R
    L-A <= k*M <= R-A
    (L-A)/M <= k <= (R-A)/M
    ceil (L-A / M) <= k <= floor(R-A / M)　とすれば整数区間にできる
    A <= X <= B (A,B in Z) のときXの個数はB-A+1
    */

    R-=A;
    L-=A;
    fprintf(stderr, "L=%lld, R=%lld\n", L,R);

    auto floor = [](ll x, ll m) {
        ll r = (x%m + m) % m; // xをmで割ったあまり(負数対応版)
        return (x-r) / m;
    };

    ll right = floor(R, M);
    ll left = floor(L+M-1, M); // ceil(x/a) = floor( (x+a-1) / a)

    fprintf(stderr, "left = %lld, right = %lld\n", left, right);
    cout << right - left + 1 << endl;
    return 0;
}