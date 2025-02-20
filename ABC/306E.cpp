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
    int N,K,Q; cin >> N >> K >> Q;
    
    vector<int> A(N,0);
    multiset<pair<int, int>> top,other;
    for(int i = 0; i < N; i++){
        if(i < K){
            top.insert(make_pair(0,i));
        }else{
            other.insert(make_pair(0,i));
        }
    }

    ll sum = 0;
    while(Q--){
        ll X,Y; cin >> X >> Y;
        X--;

        if(top.contains(make_pair(A[X], X))){
            top.erase(make_pair(A[X], X));
            top.insert(make_pair(0,-1)); // ダミーのレコード
            sum -= A[X];
        }else{
            other.erase(make_pair(A[X], X));
            
        A[X] = Y;
        other.insert(make_pair(A[X], X));
        
        // topの整理
        // for(auto [u,v] : top) cout << u << " " << v << endl;
        while(top.begin()->first < prev(other.end())->first){
            auto [a,b] = *top.begin();
            auto [c,d] = *prev(other.end());

            // printf("[%d, %d] vs [%d, %d]\n", a,b,c,d);

            // topの最下位とotherの1位をswap
            top.erase(top.find(make_pair(a,b)));
            top.insert(make_pair(c,d));
            sum -= a;
            sum += c;

            other.erase(other.find(make_pair(c,d)));
            other.insert(make_pair(a,b));
        }

        cerr << "\t";
        cout << sum << endl;
    }
    return 0;
}