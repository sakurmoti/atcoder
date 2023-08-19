#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define PI 3.141592653589793

int main(){
    double N; cin >> N;
    double x_0,y_0,x_half,y_half;
    cin >> x_0 >> y_0;
    cin >> x_half >> y_half;

    /*
    原点に対して回転行列は{(cos, -sin), (sin, cos)}なので、
    x' = xcos - ysin
    y' = xsin + ycos
    内角は 180- 360/N 度

    中心点は (X,Y) = ( (x0+x_half)/2, (y0+y_half)/2)
    */

    double midX = (x_0 + x_half)/2;
    double midY = (y_0 + y_half)/2;
    // printf("midX = %lf midY = %lf\n", midX, midY);

    //まず中心点を原点に移動し、頂点も同時に移動
    x_0 -= midX;
    y_0 -= midY;

    //p0を原点に対して回転
    double deg = 360/N;
    double theta = deg*(PI/180);
    // printf("deg = %lf\n", deg);
    double x_1 = x_0*cos(theta) - y_0*sin(theta);
    double y_1 = x_0*sin(theta) + y_0*cos(theta);

    //原点に平行移動した頂点を元に戻す
    x_1 += midX;
    y_1 += midY;

    printf("%lf %lf\n", x_1, y_1);
    return 0;
}