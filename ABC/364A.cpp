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
    bool f = false;
    for(int i = 0; i < N; i++){
        string S; cin >> S;
        if(S[1] == 'w'){
            if(f && i!=N-1){
                cout << "No" << endl;
                return 0;
            }

            f = true;
        }else{
            f = false;
        }
    }
    cout << "Yes" << endl;
    return 0;
}