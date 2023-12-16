#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    long double W,H,x,y; cin >> W >> H >> x >> y;

    // 最大でも長方形の半分の面積
    // そして長方形の中央を通れば必ず2分割可能
    long double S = (W*H)/2.00000000000;

    // (x,y)が中心でないなら中心を通る直線は一意に決まる
    int flag = ((x+x)==W && (y+y)==H);
    cout << fixed << setprecision(10) << S << " " << flag << endl;
    return 0;
}