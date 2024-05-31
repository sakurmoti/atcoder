#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N,K; cin >> N >> K;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    int sum = 0, ans = 0, idx = 0;
    while(idx < N){
        while(sum+A[idx] <= K && idx < N){
            sum += A[idx];
            idx++;
        }

        sum = 0;
        ans++;
    }

    cout << ans << endl;
    return 0;
}