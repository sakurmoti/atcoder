#include <bits/stdc++.h>
using namespace std;

const int modulo = 998244353;

int main(){
    long long A,B,C,D,E,F;
    cin >> A >> B >> C >> D >> E >> F;

    long long X=1,Y=1;

    A%=modulo;
    X *= A;
    X%=modulo;

    B%=modulo;
    X *= B;
    X%=modulo;

    C%=modulo;
    X *= C;
    X%=modulo;

    D%=modulo;
    Y *= D;
    Y%=modulo;

    E%=modulo;
    Y *= E;
    Y%=modulo;

    F%=modulo;
    Y *= F;
    Y%=modulo;

    long long ans = X-Y;
    if(ans < 0) ans += modulo;
    cout <<  ans << endl;
    return 0;
}