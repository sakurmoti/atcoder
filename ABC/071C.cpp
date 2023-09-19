#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    map<ll, int> cnt; 
    for(int i = 0; i < N; i++){
        int a; cin >> a;
        cnt[a]++;
    }

    ll h=0, w=0;
    ll S = 0;
    for(auto v : cnt){
        ll key = v.first;
        int value = v.second;
        if(value >= 4){
            h = max(h, key);
            w = max(w, key);
        }else if(value >= 2){
            if(h < w){
                h = max(h, key);
            }else{
                w = max(w, key);
            }
        }
        S = h*w;
    }

    cout << S << endl;
    return 0;
}