#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    ll H,W,M; cin >> H >> W >> M;

    vector<tuple<ll,ll,ll>> query(M);
    for(ll i = M-1; i >= 0; i--){
        ll t,a,x; cin >> t >> a >> x;
        a--;
        query[i] = make_tuple(t,a,x);
    }

    set<ll> row,col;
    map<ll, ll> colors;
    for(auto[t,a,x] : query){
        if(t == 1){
            if(row.contains(a)) continue; //上書きされている
            if(W - col.size() <= 0) continue; //足すと無駄に色が増えるのでskip
            colors[x] += W - col.size();
            row.insert(a);

        }else{
            if(col.contains(a)) continue;
            if(H - row.size() <= 0) continue;
            colors[x] += H - row.size();
            col.insert(a);
        }
    }

    // 塗っていないところはcolor = 0
    ll cnt = 0;
    for(auto [c, n] : colors){
        cnt += n;
    }
    if(cnt != (H*W)) colors[0] += (H*W) - cnt;

    cout << colors.size() << endl;
    for(auto [c, n] : colors){
        cout << c << " " << n << endl;
    }
    
    return 0;
}