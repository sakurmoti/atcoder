#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N;
    cin >> N;

    //AAbcDDEfEが美しい数字
    //A!=0
    int A=1,B,C,D,E,F;

    //Fが1の位, Eが10の位、Dが100の位...に対応
    N--;
    F = N%10;
    N /= 10;
    
    E = N%10;
    N /= 10;

    D = N%10;
    N /= 10;

    C = N%10;
    N /= 10;

    B = N%10;
    N /= 10;

    A += N%10;

    long long ans = A*1000'0000'0 + A*1000'0000 + B*1000'000 + C*1000'00 + D*1000'0 + D*1000 + E*100 + F*10 + E;
    cout << ans << endl;
    return 0;
}