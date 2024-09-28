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
    ll N,M,K; cin >> N >> M >> K;
    vector<ll> A(N);
    for(auto &_v : A) cin >> _v;

    ll modulo = K - accumulate(ALL(A), 0LL);
    cout << modulo << endl;

    vector<pair<ll, int>> B(N);
    for(int i = 0; i < N; i++){
        B[i] = make_pair(A[i], i);
    }
    sort(RALL(B));
    ll top = 0, sub=0;
    set<int> st;
    for(int i = 0; i < M; i++){
        top += B[i].first;
        st.insert(B[i].second);
    }
    sub = B[M].second;

    vector<ll> ans(N);
    for(int i = 0; i < N; i++){
        ll ok = modulo+1;
        ll ng = -1;
        while(abs(ok-ng)>=2){
            ll mid = (ok+ng)/2; // mid票獲得した場合

            ll me = A[i] + mid;
            ll block = (me+1)*M;
            ll mod = modulo - mid;

            // 上位Mに入る場合
            if(st.contains(i)){
                if(block - (top-A[i]+A[sub]) >= mod){
                    ng = mid;
                }else{
                    ok = mid;
                }
            
            }else{
                if(block - top >= mod){
                    ng = mid;
                }else{
                    ok = mid;
                }

            }
        }

        cout << ok << endl;
        if(ok>modulo){
            ans[i] = -1;
        }else{
            ans[i] = ok;
        }
    }

    for(auto &_v : ans) cout << _v << " "; cout << endl;
    return 0;
}