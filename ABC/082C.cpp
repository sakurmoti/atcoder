#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    map<int, int> mp;
    for(int i = 0; i < N; i++){
        mp[A[i]]++;
    }

    ll ans = 0;
    for(auto [u,v] : mp){
        if(u <= v){
            ans += v-u;
        }else{
            ans += v;
        }
    }
    cout << ans << endl;
    return 0;
}  