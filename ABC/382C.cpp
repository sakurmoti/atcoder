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
    int N,M; cin >> N >> M;
    vector<int> A(N),B(M);
    for(auto &_v : A) cin >> _v;
    for(auto &_v : B) cin >> _v;

    vector<pair<int, int>> C;
    C.push_back({1e9, 0});
    int len = 0;
    for(int i = 0; i < N; i++){
        if(C[len].first > A[i]){
            C.push_back({A[i], i+1});
            len++;
        }
    }

    // cout << endl;
    // for(auto [u,v] : C) cout << u << " " << v << endl;
    // cout << endl;

    for(int i = 0; i < M; i++){
        if(C[len].first > B[i]){
            cout << -1 << endl;
        }else{
            int ok = len, ng = 0;
            while(abs(ok-ng) >= 2){
                int mid = (ok+ng)/2;

                if(C[mid].first <= B[i]){
                    ok = mid;
                }else{
                    ng = mid;
                }
            }

            cout << C[ok].second << endl;
        }
        
    }

    return 0;
}