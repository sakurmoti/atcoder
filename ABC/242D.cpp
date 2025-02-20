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
    string S; cin >> S;
    int N = S.size();
    int Q; cin >> Q;

    auto rec = [&](auto self, ll depth, ll idx) -> char {
        if(depth == 0){
            return S[idx];
        }

        if(idx == 0){
            // idx==0では上の深さからA,B,Cと循環する
            string T = "ABC";
            int now = T.find(S[0]);
            return T[(depth+now)%3];
            
        }

        char c = self(self, depth-1, idx/2);
        
        if(idx%2 == 0){
            // 1個上の深さから左に分岐したもの
            if(c == 'A') return 'B'; // BC
            else if(c == 'B') return 'C'; // CA
            else return 'A'; // AB
        }else{
            // 右に分岐したもの
            if(c == 'A') return 'C';
            else if(c == 'B') return 'A';
            else return 'B';
        }


    };

    while(Q--){
        ll t,k; cin >> t >> k;
        k--;

        // cerr << '\t';
        cout << rec(rec, t, k) << endl;
    }
    return 0;
}