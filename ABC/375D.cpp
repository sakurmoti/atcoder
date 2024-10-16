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
    string S; cin >> S;
    int N = S.size();

    vector<vector<ll>> csum(30, vector<ll>(N+1, 0));
    for(int i = 0; i < N; i++){
        for(int c = 'A'; c <= 'Z'; c++){
            csum[c-'A'][i+1] = csum[c-'A'][i] + (S[i] == c);
        }
    }

    ll ans = 0;
    for(int i = 2; i <= N-1; i++){
        for(int c = 'A'; c <= 'Z'; c++){
            ans += csum[c-'A'][i-1] * (csum[c-'A'][N] - csum[c-'A'][i]); // S[i]を真ん中として考える
        }
    }

    cout << ans << endl;
    return 0;
}