#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string S; cin >> S;
    int N = S.size();
    S.insert(S.begin(), ' '); //[1,N]に

    // 0~9の値が偶数回出てたら0, 奇数回なら1
    vector<bitset<10>> bits(N+1, 0);
    // cout << "0 : "<< bits[0] << endl;
    for(int i = 1; i <= N; i++){
        int x = S[i] - '0';
        bits[i] = bits[i-1];
        bits[i][x].flip();
        // cout << i << " : " << bits[i] << endl;
    }

    // [l-1, r]のビット列が等しければ組合せになりうる
    unordered_map<bitset<10>, int> mp;
    for(int i = 0; i <= N; i++){
        mp[bits[i]]++;
    }

    ll ans = 0;
    for(auto [key, value] : mp){
        // nC2 = n*(n-1)/2
        ll n = value;
        ans += n*(n-1)/2;
    }

    cout << ans << endl;
    return 0;
}