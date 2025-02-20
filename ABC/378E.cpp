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

#include <atcoder/all>
using namespace atcoder;

int main(){
    int N,M; cin >> N >> M;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    for(int i = 0; i < N; i++){
        A[i] %= M;
    }
    // for(auto &_v : A) cout << _v << " "; cout << endl;
    
    vector<ll> csum(N+1, 0);
    for(int i = 0; i < N; i++){
        csum[i+1] = (csum[i] + A[i])%M;
    }

    // 以下を高速化することを考える
    // csum[r] < csum[l]なる個数のみわかればrを固定して解ける
    // for(int l = 0; l <= N; l++){
    //     for(int r = l+1; r <= N; r++){
    //         if((csum[r] - csum[l]) < 0){
    //             ans += (csum[r] - csum[l]) + M;
    //         }else{
    //             ans += (csum[r] - csum[l]);
    //         }
    //     }
    // }

    fenwick_tree<ll> fw(M+1);

    // csum[r]の総和を高速に求めるための累積和
    vector<ll> ccsum(N+1, 0);
    for(int i = 0; i < N; i++){
        ccsum[i+1] = ccsum[i] + csum[i+1];
    }

    ll ans = 0;
    for(int r = 1; r <= N; r++){
        ll cnt = fw.sum(csum[r]+1, M);
        fw.add(csum[r], 1);

        ans += csum[r]*r - ccsum[r-1] + M*cnt;
    }

    cout << ans << endl;
    return 0;
}