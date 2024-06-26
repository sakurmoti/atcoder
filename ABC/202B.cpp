#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int A,B,M; cin >> A >> B >> M;
    vector<int> a(A),b(B);
    for(auto &_v : a) cin >> _v;
    for(auto &_v : b) cin >> _v;

    int ma = *min_element(ALL(a));
    int mb = *min_element(ALL(b));

    ll ans = ma+mb;
    for(int i = 0; i < M; i++){
        int x,y,c;
        cin >> x >> y >> c;
        x--;
        y--;

        ll charge = a[x] + b[y] - c;
        chmin(ans, charge);
    }

    cout << ans << endl;
    return 0;
}