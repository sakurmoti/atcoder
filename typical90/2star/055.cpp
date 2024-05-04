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

int main(){
    ll N,P,Q; cin >> N >> P >> Q;
    mint::set_mod(P);

    vector<mint> A(N);
    for(int i = 0; i < N; i++){
        int a; cin >> a;
        A[i] = a;
    }

    ll ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            for(int k = j+1; k < N; k++){
                for(int l = k+1; l < N; l++){
                    for(int m = l+1; m < N; m++){
                        mint x = A[i] * A[j] * A[k] * A[l] * A[m];
                        if(x.val() == Q) ans++; 
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}