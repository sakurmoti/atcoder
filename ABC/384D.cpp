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
    ll N,S; cin >> N >> S;
    vector<ll> A(N+1, 0);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }

    vector<ll> csum(10*N, 0);
    map<ll, ll> dict;
    dict[0] = 0;
    for(int i = 1; i <= 3*N; i++){
        csum[i] = csum[i-1] + A[((i-1)%N) + 1];
        dict[csum[i]] = i;

        // cout << csum[i] << " ";
    }
    // cout << endl;

    if(S >= csum[N]){
        // cout << "part1:\n";
        // [i,N]と[0,j]でSになる区間があればよい
        S %= csum[N];
        S += csum[N];
        for(int i = 0; i <= 2*N; i++){
            ll prev = (2*csum[N]) - csum[i];
            ll suff = S - prev;

            if(dict.contains(suff)){
                // cout << i << " " << dict[suff] << endl;
                cout << "Yes" << endl;
                return 0;
            }
        }

    }else{
        // cout << "part2:\n";
        // [i,j)でSになる区間があればよい
        for(int i = 0; i <= N; i++){
            ll suff = S - csum[i];

            if(dict.contains(suff)){
                // cout << i << " " << dict[suff] << endl;
                cout << "Yes" << endl;
                return 0;
            }
        }

    }
    cout << "No" << endl;
    return 0;
}