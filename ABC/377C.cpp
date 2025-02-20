#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
constexpr int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
struct Point{int x,y; Point(){}; Point(int _x, int _y):x(_x),y(_y){}};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    ll N,M; cin >> N >> M;
    
    set<pair<int, int>> st;
    for(int i = 0; i < M; i++){
        int a,b; cin >> a >> b;
        a--; b--;
        st.insert(make_pair(b,a));

        for(int j = 0; j < 8; j++){
            ll ny = a + dy[j];
            ll nx = b + dx[j];

            if(isRange(nx, 0LL, N) && isRange(ny, 0LL, N)){
                st.insert(make_pair(nx, ny));
            }
        }
    }

    ll len = (ll)st.size();
    // cerr << len << endl;
    cout << N*N - len << endl;
    return 0;
}