#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N = 64;
    vector<ll> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    unsigned long long ans = 0;
    unsigned long long cnt = 1;
    for(int i = 0; i < N; i++){
        ans = ans + A[i]*cnt;
        cnt*=2;
    }
    cout << ans << endl;
    return 0;
}