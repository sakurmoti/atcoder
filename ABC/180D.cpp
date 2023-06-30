#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll X,Y,A,B;
    cin >> X >> Y >> A >> B;

    ll ep = 0;

    /*
    A*X <= X+B なら倍にするほうが良い
    <=> X(A-1) <= B
    <=> X <= B/(A-1)

    X <= B/(A-1)を満たす限りA倍していく
    */

    while(true){
        if(X*A >= Y) break;

        if(X <= B/(A-1)) X *= A;
        else break;
        ep++;
    }
    
    /*
    X+ kB < Y を満たす最大のkを足せばよい
    <=> k < (Y-X)/B
    */

    ll k = (Y-X)/B;
    if((Y-X)%B == 0) k--;
    ep += k;
    cout << ep << endl;

    return 0;
}