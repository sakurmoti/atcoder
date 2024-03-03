#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;

int main(){
    int N; cin >> N;
    vector<int> T(N);
    for(auto &_v : T) cin >> _v;

    sort(ALL(T));
    ll sum = 0, buf = 0;
    for(int i = 0; i < N; i++){
        buf += T[i];
        sum += buf;
    }

    map<int, int> dist;
    for(int i = 0; i < N; i++){
        dist[T[i]]++;
    }

    // calc x!
    auto f = [&](auto self, mint x) -> mint {
        if(x==1) return 1;
        return x * self(self, x-1);
    };

    mint per(1);
    for(auto [k,v] : dist){
        per *= f(f, v);
    }

    cout << sum << endl;
    cout << per.val() << endl;
    return 0;
}