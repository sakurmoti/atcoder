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
    int N; cin >> N;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    // 操作は素因数を1つ以上減らす操作に相当
    // あとはただのNim
    vector<int> g(N, 0);
    for(int i = 0; i < N; i++){
        int x = A[i];
        for(int j = 2; j*j <= A[i]; j++){
            while(x%j == 0){
                g[i]++; // 素因数の個数が山の個数 = grundy数そのもの
                x /= j;
            }
        }
        if(x != 1) g[i]++;
    }

    int xorSum = 0;
    for(int i = 0; i < N; i++){
        xorSum ^= g[i];
    }

    if(xorSum != 0) cout << "Anna" << endl;
    else cout << "Bruno" << endl;
    return 0;
}