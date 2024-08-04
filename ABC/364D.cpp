#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N,Q; cin >> N >> Q;
    vector<ll> A(N);
    for(auto &_v : A) cin >> _v;
    sort(ALL(A));

    // 距離midの中に何個点が存在するかで二分探索
    while(Q--){
        int b,k; cin >> b >> k;

        ll ok = 1e9;
        ll ng = -1;
        while(abs(ok-ng)>=2){
            ll mid = (ok+ng)/2;

            int r = upper_bound(ALL(A), b+mid) - A.begin();
            int l = lower_bound(ALL(A), b-mid) - A.begin();

            if(r-l >= k){
                ok = mid;
            }else{
                ng = mid;
            }
        }

        cout << ok << endl;
    }
    return 0;
}