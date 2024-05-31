#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

int main(){
    int N; cin >> N;
    vector<ll> A(N);
    for(auto &_v : A) cin >> _v;

    vector<int> len(N);
    for(int i = 0; i < N; i++){
        len[i] = to_string(A[i]).size();
    }
    // for(auto &_v : len) cout << _v << " "; cout << endl;

    // f(s,t) = s * 10^len[t] + t;
    mint ans = 0;

    // t (A[j]) だけの総和
    for(int i = 0; i < N; i++){
        ans += (A[i] * i);
    }
    // cout << ans.val() << endl;

    vector<vector<int>> len_idx(20);
    for(int i = 0; i < N; i++){
        len_idx[len[i]].push_back(i);
    }

    for(int i = 0; i < N; i++){    
        for(int j = 0; j <= 10; j++){
            int idx = upper_bound(ALL(len_idx[j]), i) - len_idx[j].begin();
            ll cnt = len_idx[j].size() - idx;

            mint p = mint(10).pow(j);
            mint m = (A[i] * p * cnt);
            ans += m;
        }
    }

    cout << ans.val() << endl;
    return 0;
}