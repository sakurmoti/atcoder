#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    ll S; cin >> S;
    
    // p1を原点に固定しても良い
    // このとき面積はdet([x2,x3], [y2,y3]) / 2
    // S = det([x2,x3], [y2,y3])
    // S = x2*y3 - x3*y2
    // x2=1e9, y2=1としてみれば
    // S = 1e9 * y3 - x3
    // これはSを1e9で割った商から求まる

    int x1=0,y1=0;
    int x2=1e9,y2=1;

    int m = 1e9;
    int x3 = (m - S%m)%m; // あるkにおいて S+x3 = m*kが成立 <=> S+x3がmの倍数になるようにx3を定める

    int y3 = (S+x3) / m; // S = m*y3 - x3 を変形しただけ

    printf("%d %d %d %d %d %d\n", x1,y1,x2,y2,x3,y3);
    return 0;
}