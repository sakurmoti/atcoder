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
    string S; cin >> S;

    int N = 26;
    string alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int now = -1;
    for(int i = 0; i < N; i++){
        if(S[i] == 'A') now = i;
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(alp[i] == S[j]){
                ans += abs(now-j);
                now = j;
            }
        }
    }

    cout << ans << endl;
    return 0;
}