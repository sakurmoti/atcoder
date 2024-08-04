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
    vector<ll> X(N),Y(N);
    for(int i = 0; i < N; i++){
        cin >> X[i] >> Y[i];
    }

    sort(ALL(X));
    sort(ALL(Y));
    ll midx = X[N/2];
    ll midy = Y[N/2];
    // cout << midx << " " << midy << endl;

    ll ans = 0;
    for(int i = 0; i < N; i++){
        ans += abs(X[i] - midx) + abs(Y[i] - midy);
    }

    cout << ans << endl;
    return 0;
}