#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
struct Point{int x, y;};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N; cin >> N;
    
    vector<int> R,L;
    for(int i = 0; i < N; i++){
        int a; cin >> a;
        char c; cin >> c;

        if(c == 'R'){
            R.push_back(a);
        }else{
            L.push_back(a);
        }
    }

    int ans = 0;
    for(int i = 1; i < R.size(); i++){
        ans += abs(R[i-1] - R[i]);
    }

    for(int i = 1; i < L.size(); i++){
        ans += abs(L[i-1] -L[i]);
    }

    cout << ans << endl;
    return 0;
}