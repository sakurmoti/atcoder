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

void greedy(int &N, vector<ll> &A){
    ll sum = 0;
    for(int i = 0; i < N-1; i++){
        ll k = A[i];
        for(int j = i+1; j < N; j++){
            k = k xor A[j];
            sum += k;

            // printf("(%d, %d) = %lld\n", i,j,k);
        }
    }

    cout << sum << "\n";
}

int main(){
    int N; cin >> N;
    vector<ll> A(N);
    for(auto &_v : A) cin >> _v;

    greedy(N,A);

    ll ans = 0;
    for(int i = 0; i < N; i++){
        ans += A[i] * (i+1) * (N-i);
    }
    cout << ans << endl;
    return 0;
}