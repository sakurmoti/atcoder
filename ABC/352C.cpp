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
    vector<ll> A(N),B(N);
    ll sumA = 0;
    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i];
        sumA += A[i];
    }

    ll ans = 0;
    for(int i = 0; i < N; i++){
        chmax(ans, sumA - A[i] + B[i]);
    }

    cout << ans << endl;
    return 0;
}