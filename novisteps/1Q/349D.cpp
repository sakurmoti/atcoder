#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    ll A,B; cin >> A >> B;

    ll left = 0;
    ll right = (1LL << 62);

    vector<pair<ll, ll>> ans;
    auto solve = [&](auto self, ll L, ll R) -> void {
        // 区間内
        if(A <= L && R <= B){
            ans.push_back(make_pair(L,R));
            return;
        }

        ll mid = (L+R)/2;

        if(B <= mid){
            // segtreeの左ブロックへ
            self(self, L, mid);
            return;
        }
        
        if(mid <= A){
            // segtreeの右ブロックへ
            self(self, mid, R);
            return;
        }

        self(self, L, mid);
        self(self, mid, R);
    };

    solve(solve, left, right);

    cout << ans.size() << endl;
    for(auto &_v : ans) cout << _v.first << " " << _v.second << "\n";
    return 0;
}