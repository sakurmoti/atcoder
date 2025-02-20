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
    int K; cin >> K;
    string S,T; cin >> S >> T;

    int lenS = S.size();
    int lenT = T.size();

    int Maxi = lenS + lenT;
    int offset = Maxi + 1;
    vector<int> A(offset*2 + 1, 0);

    A[1+offset] = 0;

    auto solve = [&]() -> int {
        for(int d = 0; d <= Maxi; d++){
            for(int k = -d; k <= d; k+=2){
                int kk = k + offset;

                int x = (k == -d || (k != d && A[kk-1] < A[kk+1])) ? A[kk+1] : A[kk-1];
                int y = x - k;

                while(x < lenS && y < lenT && S[x] == T[y]){
                    x++;
                    y++;
                }

                A[kk] = x;
                if(x >= lenS && y >= lenT){
                    return d;
                }
            }
        }

        return -1;
    };

    int m = max(lenS, lenT);
    int d = solve();

    printf("m=%d, d=%d\n", m, d);
    double ans = 1 - (d/m);
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}