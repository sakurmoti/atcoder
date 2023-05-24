#include <bits/stdc++.h>
using namespace std;

void solve(){
    int L,R;
    cin >> L >> R;

    //R-L=x, R-(L+1)=x-1, ... R-x=L の x-L+1個
    //つまり(R-L)-L+1 = R-2L+1個

    int count = (R-2L)+1;

    long long sum = (1 + (R-2*L+1))*count/2;
    cout << sum << endl;

    return;
}

int main(){
    int T;
    cin >> T;

    for(int t = 0; t < T; t++){
        solve();
    }
    return 0;
}