#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N;
    cin >> N;

    if(N>=0){
        cout << N%998244353 << endl;
    }else{
        if(N%998244353 != 0) cout << 998244353 + N%998244353 << endl;
        else cout << 0 << endl;
    }
    return 0;
}