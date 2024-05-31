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
using mint = modint;

vector<pair<ll, ll>> sep(ll A, ll B){
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

    return ans;
}

int main(){
    int N; cin >> N;
    ll L,R; cin >> L >> R;
    mint::set_mod(100);

    // [L,R]をいい数列(ABC349D)に分解
    auto v = sep(L, R+1);

    // for(auto [f,s] : v){
    //     cout << f << " " << s << endl;
    // }

    mint ans(0);
    for(auto [l,r] : v){
        int i = 0;
        int cp = l;
        while(cp%2 == 0){
            i++;
            cp/=2;
        }

        int j = cp;

        cout << "? " << i << " " << j << endl;

        int t; cin >> t;
        if(t == -1){
            assert("fail");
            return 0;
        }
        ans += t;
    }

    cout << "! " << ans.val() << endl;
    return 0;
}