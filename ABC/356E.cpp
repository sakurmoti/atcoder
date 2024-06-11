#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N; cin >> N;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    int M = *max_element(ALL(A));
    vector<ll> csum(M+1,0); // 出現回数の累積和
    for(int i = 0; i < N; i++){
        csum[A[i]]++;
        chmax(M, A[i]);
    }

    for(int i = 0; i < M; i++){
        csum[i+1] += csum[i];
    }

    for(auto &_v : csum) cout << _v << " "; cout << endl;

    auto f = [&](int d, int n){
        // f(d,n) := floor(A[j]/d) == nを満たすjの個数
        // n*d <= A[j] < (n+1)*d のjの個数
        // csum[l] - csum[r] := (l, r]の総和
        return csum[min(M, (n+1)*d-1)] - csum[n*d-1];
    };

    ll ans = 0;
    for(ll i = 1; i <= M; i++){
        ll x = csum[i] - csum[i-1]; // xの出現回数
        for(ll j = 1; i*j <= M; j++){
            ans += x * j * f(i, j);
        }
        ans -= x*(x+1)/2;
    }

    cout << ans << endl;
    return 0;
}