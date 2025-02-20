#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
struct Point{int x,y; Point(){}; Point(int _x, int _y):x(_x),y(_y){}};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N,Q; cin >> N >> Q;
    vector<tuple<int,int,int>> A(N);
    for(int i = 0; i < N; i++){
        // マスiは[first,second]の区間に含まれる, 色はthird
        A[i] = make_tuple(i,i,i);
    }

    while(Q--){
        int q;
        cin >> q;
        
        if(q==1){
            int x,c; cin >> x >> c;
            x--; c--;

            auto [l,r,c] = A[i];
            if(isRange(l-1,0,N)){
                auto [lp, rp, cp] = A[l-1];
                if(c == cp){
                    
                }
            }

        }else{
            int c; cin >> c;
            c--;
            cout << color[c] << endl;
        }
    }
    return 0;
}