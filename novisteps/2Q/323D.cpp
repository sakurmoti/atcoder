#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    ll N; cin >> N;
    map<ll,ll> dict;
    for(int i = 0; i < N; i++){
        ll s,c; cin >> s >> c;
        dict[s] += c;
    }

    ll sum = 0;
    for(auto [k,v] : dict){
        if(v >= 2) dict[2*k] += (v/2);
        if(v%2 != 0) sum++;
    }

    cout << sum << endl;
    return 0;
}