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
    string X; cin >> X;
    int N = X.size();
    int cnt = 0;
    for(int i = N-1; i >= 0; i--){
        if(X[i] != '0'){
            break;
        }
        cnt++;
        X.pop_back();
    }

    if(cnt < 3) cout << X << endl;
    else{
        X.pop_back();
        cout << X << endl;
    }
    return 0;
}