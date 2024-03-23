#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    ll N,A,B; cin >> N >> A >> B;

    // 等差数列の計算
    auto calc_sum = [&](ll first, ll last, ll number) -> ll {
        return ( (first + last) * number ) / 2;
    };
    
    ll all_sum = calc_sum(1, N, N); // 1からNの総和
    ll sumA = calc_sum(A, A * (N/A), N/A);
    ll sumB = calc_sum(B, B * (N/B), N/B);
    
    ll lcmAB = lcm(A,B);
    ll sumAB = calc_sum(lcmAB, lcmAB * (N/lcmAB), N/lcmAB);
    // fprintf(stderr, "all = %lld, sA = %lld, sB = %lld, sAB = %lld\n", all_sum, sumA, sumB, sumAB);

    cout << all_sum - sumA - sumB + sumAB << endl;
    return 0;
}