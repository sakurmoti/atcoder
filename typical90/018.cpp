#include <bits/stdc++.h>
using namespace std;

long double PI = 3.14159265358979;

int main(){
    long double T,L,X,Y;
    cin >> T >> L >> X >> Y;

    int Q;
    cin >> Q;
    vector<long double> minites(Q);
    for(int i = 0; i < Q; i++) cin >> minites.at(i);

    for(int i = 0; i < Q; i++){
        //thetaはN分のときの角度(度数法)。Rは観覧車の半径
        long double R = L/2.0;
        long double theta = 2.0 * PI * minites.at(i)/T;

        //y,zは観覧車の座標
        long double y = -R*sin(theta);
        long double z = R - R * cos(theta);

        //arctanは弧度法で値が返ってくることに注意
        //atan(y,x)でarctan(y/x)の値を求めることができる。
        long double ans = atan2(z, sqrt((Y-y)*(Y-y) + X*X));

        cout << ans*180.0L/PI << endl;
    }
    return 0;
}