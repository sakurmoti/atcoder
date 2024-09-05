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

int N,K;
vector<int> R;
void solve(vector<int> &v, int idx, int sum){
    if(idx == N){
        if(sum%K==0){
            for(auto &_v : v) cout << _v << " "; cout << endl;
        }
        return;
    }

    for(int i = 1; i <= R[idx]; i++){
        v[idx] = i;
        solve(v, idx+1, sum+i);
    }
}

int main(){
    cin >> N >> K;
    R.resize(N);
    for(auto &_v : R) cin >> _v;

    vector<int> ans(N, 0);
    solve(ans, 0, 0);
    return 0;
}