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
    ll N; cin >> N;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    // dict[i] := 数字iのidxの集合(ただしAの両端にiを追加したものとする)
    map<int, vector<ll>> dict;
    set<int> st(ALL(A));
    for(auto v : st){
        dict[v].push_back(0);
    }

    for(int i = 1; i <= N; i++){
        dict[A[i-1]].push_back(i);
    }

    for(auto v : st){
        dict[v].push_back(N+1);
    }

    ll ans = 0;
    for(auto [f,s] : dict){
        ll all = (N*(N+1)) /2;
        
        for(int i = 1; i < s.size(); i++){
            ll n = (s[i]-1) - (s[i-1]+1) +1;
            all -= (n*(n+1)) /2;
        }

        ans += all;
    }

    cout << ans << endl;
    return 0;
}