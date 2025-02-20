#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
// constexpr int dx[4] = {1, 0, -1, 0};
// constexpr int dy[4] = {0, 1, 0, -1};
struct Point{int x,y; Point(){}; Point(int _x, int _y):x(_x),y(_y){}};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    ll R; cin >> R;
    // 原点に中心があるとして考える
    
    // 原点の正方形を数える
    long double dx[4] = {0.5, 0.5, -0.5, -0.5};
    long double dy[4] = {0.5, -0.5, 0.5, -0.5};
    ll origin = 0;
    bool flag = true;
    for(int i = 0; i < 4; i++){
        long double nx = dx[i];
        long double ny = dy[i];
        if(nx*nx + ny*ny > R*R){
            flag = false;
        }
    }
    if(flag){
        origin++;
    }


    // 軸上の正方形を数える(原点を除く)
    // (x=0, y>0.5)の正方形の数の4倍
    ll overLine = 0;
    for(ll y = 1; y <= R; y++){
        flag = true;
        for(int i = 0; i < 4; i++){
            long double nx = dx[i];
            long double ny = y + dy[i];
            if(nx*nx + ny*ny > R*R){
                flag = false;
            }
        }

        if(flag){
            overLine += 4;
        }
    }
    
    // 扇形に含まれる正方形を数える
    ll sector = 0;
    ll y = R;
    for(int x = 1; x <= R; x++){
        while(y > 0){
            flag = true;
            for(int i = 0; i < 4; i++){
                long double nx = x + dx[i];
                long double ny = y + dy[i];
                if(nx*nx + ny*ny > R*R){
                    flag = false;
                }
            }

            if(flag){
                sector += 4*y;
                break;
            }else{
                y--;
            }
        }
    }

    // printf("%lld, %lld, %lld\n", origin, overLine, sector);
    cout << origin + overLine + sector << endl;
    return 0;
}