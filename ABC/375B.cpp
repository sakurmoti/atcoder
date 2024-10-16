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
    int N; cin >> N;
    vector<ll> X(N+1),Y(N+1);
    X[0] = 0; Y[0] = 0;
    for(int i = 1; i <= N; i++){
        cin >> X[i] >> Y[i];
    }
    X.push_back(0);
    Y.push_back(0);

    double cost = 0;
    for(int i = 1; i <= N+1; i++){
        ll distX = (X[i] - X[i-1]) * (X[i] - X[i-1]);
        ll distY = (Y[i] - Y[i-1]) * (Y[i] - Y[i-1]);

        cost += sqrtl(distX + distY);
    }

    cout << fixed << setprecision(10) << cost << endl;
    return 0;
}