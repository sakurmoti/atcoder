#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N,M; cin >> N >> M;
    vector<int> A(N),B(M);
    for(auto &_v : A) cin >> _v;
    for(auto &_v : B) cin >> _v;
    sort(ALL(B));

    multiset<int> box;
    for(int i = 0; i < N; i++){
        box.insert(A[i]);
    }

    ll ans = 0;
    for(int i = 0; i < M; i++){
        auto itr = box.lower_bound(B[i]);
        if(itr == box.end()){
            cout << -1 << endl;
            return 0;
        }
        ans += *itr;
        box.erase(itr);
    }

    cout << ans << endl;
    return 0;
}