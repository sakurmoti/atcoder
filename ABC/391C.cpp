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
    int N,Q; cin >> N >> Q;
    
    vector<int> bird(N, 0), A(N, 1);
    iota(ALL(bird), 0);
    int ans = 0;
    while(Q--){
        int q; cin >> q;
        if(q == 1){
            int p,h; cin >> p >> h;
            p--; h--;

            A[bird[p]]--;
            if(A[bird[p]] == 1) ans--;
            
            bird[p] = h;
            
            if(A[bird[p]] == 1) ans++;
            A[bird[p]]++;
        
        }else{
            cerr << "\t";
            cout << ans << endl;
        }

    }
    return 0;
}