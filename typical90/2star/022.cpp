#include <bits/stdc++.h>
using namespace std;

//ユークリッドの互除法
long long gcd(long long x, long long y){
    long long Q = x/y;
    long long M = x%y;
    long long ret=0;

    if(M == 0){
        return y;
    }else{
        ret = gcd(y,M);
    }

    return ret;
}

int main(){
    long long A,B,C;
    cin >> A >> B >> C;

    /*A,B,Cがrで割り切れるなら辺rの正方形で分割できる
    このとき、(a/r -1)+(b/r -1)+(c/r -1)回で切れる
    つまり、rが大きければ大きいほど切る回数が減る
    ゆえに、A,B,Cを同時に割り切れる最大値Rを探すので最大公約数を探すのに同じ*/

    /*最大公約数Rはユークリッドの互除法で探す
    (A,Bの最大公約数)と(C)の最大公約数が(A,B,C)の最大公約数に等しい*/
    long long R = gcd(gcd(A,B), C);
    cout << (A/R -1)+(B/R -1)+(C/R -1) << endl;

    return 0;
}