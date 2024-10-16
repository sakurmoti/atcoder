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
    int N,X; cin >> N >> X;
    vector<int> A(N),B(N),P(N),Q(N);
    for(int i = 0; i < N; i++){
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    // 製造能力wに対して二分探索を考える
    ll ok = 0;
    ll ng = 1e10; // 上界はA[i]=100, P[i]=1, X=1e7のときで1e9
    while(abs(ok-ng) >= 2){
        ll mid = (ok+ng)/2;

        ll budget = 0;
        // 各工程で製造能力midを満たす最小の予算の探索
        for(int i = 0; i < N; i++){
            ll mini = 1e18; // 1工程を満たす最小の予算

            for(int j = 0; j <= A[i]; j++){
                ll x = Q[i]*j; // Tをj台購入
                
                if(B[i]*j < mid){
                    // Sを足りない分購入
                    // 切り上げの処理は ceil(a/b) = (a+b-1)/b
                    x += ( (mid-B[i]*j + (A[i]-1)) / A[i] ) * P[i];
                }

                chmin(mini, x);
            }

            for(int j = 0; j <= B[i]; j++){
                ll x = P[i]*j; // Sをj台購入
                
                if(A[i]*j < mid){
                    // Tを足りない分購入
                    x += ( (mid-A[i]*j + (B[i]-1)) / B[i] ) * Q[i];
                }

                chmin(mini, x);
            }

            budget += mini;
        }

        cerr << "mid = " << mid << " \n";
        cerr << "budget = " << budget << " \n";

        if(budget <= X){
            ok = mid;
        }else{
            ng = mid;
        }
    }

    cout << ok << endl;
    return 0;
}