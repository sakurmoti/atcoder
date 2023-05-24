#include <bits/stdc++.h>
using namespace std;

int main(){
    int X,Y;
    cin >> X >> Y;

    //X*1もXの倍数
    //XがYの倍数ならkX = k(lY)となりYの倍数にしかならないので-1を、
    //そうでないならXを出力すればよい

    int ans = X%Y==0 ? -1 : X;
    cout << ans << endl;
    return 0;
}