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
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    vector<bitset<32>> B(N);
    for(int i = 0; i < N; i++){
        B[i] = bitset<32>(A[i]);
    }

    // for(auto &_v : B) cout << _v << "\n"; cout << "\n";

    // 累積xor
    vector<vector<int>> cxor(32, vector<int>(N+1, 0));
    for(int i = 0; i < 32; i++){
        for(int j = 0; j < N; j++){
            cxor[i][j+1] = cxor[i][j] xor B[j][i];
        }
    }

    // for(auto &_v : cxor){ for(auto &_vv : _v) cout << _vv << " "; cout << endl; }

    ll ans = 0;
    for(int b = 0; b < 31; b++){
        ll cnt0 = 1, cnt1 = 0, sumB = 0;
        for(int i = 0; i < N; i++){
            if(cxor[b][i+1] == 0) cnt0++;
            else cnt1++;

            sumB += B[i][b];
        }

        // printf("%lld, %lld, %lld, %d\n", cnt0,cnt1,sumB, 1<<b);
        ans += (cnt0 * cnt1 - sumB) * (1 << b);
    }

    cout << ans << endl;
    return 0;
}