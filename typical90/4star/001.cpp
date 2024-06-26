#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    ll N,L,K; cin >> N >> L >> K;
    vector<ll> A(N+1,0);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }
    A.push_back(L);

    int ok = 0;
    int ng = L;
    while(abs(ok-ng) >= 2){
        int mid = (ok+ng)/2;

        ll split = 0;
        int prev = 0;
        for(int i = 1; i <= N+1; i++){
            if(A[i] - A[prev] >= mid){
                // cout << A[i] - A[prev] << endl;

                prev = i;
                split++; // mid以上のようかんをsplit個分作れる
            }
        }

        if(split >= K+1){
            ok = mid;
        }else{
            ng = mid;
        }
    }

    cout << ok << endl;
    return 0;
}