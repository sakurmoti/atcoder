#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a,b,c;
    cin >> a >> b >> c;

    /*long longの最大値は9.2×10^18くらい
    c^bの最大値は13^17でこれは8.8×10^18くらい
    つまり全部long longで表せるということ*/

    long long d=1;
    for(int i = 0; i < b; i++){
        d*=c;
    }

    cout << "a=" << a << " d=" << d << endl;

    if(a < d) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}