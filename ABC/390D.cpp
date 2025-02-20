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

int main(){
    int N; cin >> N;
    vector<ll> A(N);
    for(auto &_v : A) cin >> _v;

    set<ll> ans;
    set<vector<ll>> st;
    auto solve = [&](auto self, vector<ll> &B, ll xorSum) -> void {
        int M = B.size();
        // for(auto &v : B) cout << v << " "; cout << endl;
        if(st.contains(B)) return;
        st.insert(B);
        ans.insert(xorSum);

        for(int i = 0; i < M; i++){
            auto cp = B;
            for(int j = i+1; j < M; j++){
                cp[i] = B[i]+B[j];
                cp[j] = 0;
                self(self, cp, xorSum^B[i]^B[j]^(B[i]+B[j]) );
                cp[j] = B[j];
            }
        }
    };

    ll xsum = 0;
    for(auto &v : A) xsum ^= v;

    solve(solve, A, xsum);
    cout << st.size() << endl;
    cout << ans.size() << endl;
    return 0;
}