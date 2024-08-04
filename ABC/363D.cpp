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

ll TEN(int x){return x==0 ? 1 : TEN(x-1)*10;}

int main(){
    ll N; cin >> N;

    if(N==1){
        cout << 0 << endl;
        return 0;
    }
    N--;

    // d桁の回文数の個数はl = (d+1)/2としたとき
    // 先頭の0を除いた 9 * 10^(l-1)
    ll cnt = 0;
    for(int d = 1; d < 100; d++){
        int l = (d+1)/2;
        ll buf = 9*TEN(l-1);

        if(N <= cnt+buf){
            // 答える回文数はd桁のx番目
            ll x = N-cnt-1; //0-idx
            // cout << d << endl;
            // cout << x << endl;

            // 前半を作って折り返すことを考える
            ull half = TEN(l-1);
            half += x;
            string ans = to_string(half);
            if(d%2==0){
                cout << ans;
                reverse(ALL(ans));
                cout << ans << endl;
            }else{
                cout << ans;
                ans.pop_back();
                reverse(ALL(ans));
                cout << ans << endl;
            }
            return 0;
        }

        cnt += buf;
    }
    return 0;
}