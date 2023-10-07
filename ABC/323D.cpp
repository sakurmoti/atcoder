#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    map<ll, ll> slime;
    for(int i = 0; i < N; i++){
        int s,c;
        cin >> s >> c;
        slime[s] += c;
    }

    // スライムが最小 -> 合成できるものは全部する
    ll ans = 0;
    for(auto v : slime){
        ll s = v.first;
        ll c = v.second;

        // printf("s=%lld, c=%lld\n",s,c);
        ll next = c/2;
        ans += c%2;

        if(next != 0) slime[2*s] += next;
        
    }

    cout << ans << endl;
    return 0;
}