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
    
    map<int, vector<pair<int, char>>> field; //field[y] = {x, color}
    for(int i = 0; i < M; i++){
        int y,x; cin >> y >> x;
        char c; cin >> c;

        field[y].push_back({x,c});
    }
    
    int limit = N+1; // 黒の限界を各時点で
    for(auto [y, vec] : field){
        sort(ALL(vec)); // 横に切ったとき、左から見ていく
        bool flag = false;
        
        for(auto [x, c] : vec){
            if(c == 'W'){
                flag = true;
                chmin(limit, x);
                
            }else{
                if(flag || x >= limit){
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}