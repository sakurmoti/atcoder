#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    vector<string> S(N);
    for(auto &_v : S) cin >> _v;

    map<string, ll> cnt;
    for(int i = 0; i < N; i++){
        string s = S[i];
        sort(s.begin(), s.end());
        cnt[s]++;
    }

    // nC2 = n*(n-1)/2
    ll ans = 0;
    for(auto v : cnt){
        ll m = v.second;
        ans += m*(m-1)/2;
    }
    cout << ans << endl;

    return 0;
}