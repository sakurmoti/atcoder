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
    int N,Q; cin >> N >> Q;

    int L = 0;
    int R = 1;

    auto check = [&](int hand, int other, int target){
        // 時計回り
        int now = hand;
        int c1 = 0;
        while(now != target){
            now++;
            now %= N;

            if(now == other){
                c1 += 1e6;
            }
            c1++;
        }

        // 反時計回り
        now = hand;
        int c2 = 0;
        while(now != target){
            now += N-1;
            now %= N;

            if(now == other){
                c2 += 1e6;
            }
            c2++;
        }

        // cout << c1 << " " << c2 << endl;
        return min(c1, c2);
    };

    ll ans = 0;
    while(Q--){
        char H; cin >> H;
        int T; cin >> T;
        T--;

        if(H == 'L'){
            ans += check(L, R, T);
            L = T;
        }else{
            ans += check(R, L, T);
            R=T;
        }
    }

    cout << ans << endl;
    return 0;
}