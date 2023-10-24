#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    vector<int> d(N);
    for(auto &_v : d) cin >> _v;

    ll ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            ans += d[i]*d[j];
        }
    }
    cout << ans << endl;
    return 0;
}