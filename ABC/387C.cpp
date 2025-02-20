#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
struct Point{int x,y; Point(){}; Point(int _x, int _y):x(_x),y(_y){}};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    ll L,R; cin >> L >> R;

    // [10, N]の範囲のヘビ数が分かればよい
    auto snake = [&](ll N) -> ll {
        if(N < 10) return 0;

        // printf("N: %lld\n", N);
        string num = to_string(N);
        ll k = num.size(); // 桁数
        
        // [10, 100), [100, 1000) .. [10^(k-1), N]で区切る
        // まずは[10, 100) .. [10^(k-2), 10^(k-1))のヘビ数の個数を求める
        ll l = 1;
        ll r = 10;
        ll ret = 0;
        for(ll i = 1; i <= k-2; i++){
            l *= 10; // 10^i
            r *= 10;

            // [10^i, 10^(i+1))のヘビ数の個数を求める
            ll sum = 0;
            for(ll x = 1; x <= 9; x++){ // 先頭の数字を固定する
                // 先頭除いたi桁はx未満の順列
                ll tmp = 1;
                for(ll j = 0; j < i; j++){
                    tmp *= x;
                }
                sum += tmp;
            }
            ret += sum;
        }

        // [10^(k-1), N]のヘビ数の個数を求める
        l *= 10;
        r = N;
        ll rx = to_string(r)[0] - '0'; // rの先頭の数字
        // [10^(k-1), rx*10^(k-1) )の範囲は同じように考えられる
        for(ll x = 1; x <= rx; x++){
            // 先頭除いたk-1桁はx未満の順列
            ll tmp = 1;
            for(ll i = 0; i < k-1; i++){
                if(x==rx) tmp *= min(x, ll(num[i+1]-'0'+1));
                else tmp *= x;
            }
            ret += tmp;
        }
        return ret;
    };

    // ll X; cin >> X;
    // printf("snake(X) = %lld\n", snake(X));
    // return 0;

    ll Ra = snake(R);
    ll La = snake(L-1);
    printf("La: %lld, Ra: %lld\n", La, Ra);
    cout << Ra - La << endl;
    return 0;
}