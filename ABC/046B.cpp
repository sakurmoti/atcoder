#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,K; cin >> N >> K;
    ll ans = K;
    for(int i = 0; i < N-1; i++){
        ans *= (K-1);
    }
    cout << ans << endl;
    return 0;
}