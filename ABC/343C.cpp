#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    ll N; cin >> N;
    
    ll ans = 1;
    for(ll i = 0; i*i*i <= N; i++){
        string x = to_string(i*i*i);
        // cout << x << endl;
        
        int L = x.size();
        bool flag = true;
        for(int j = 0; j < L; j++){
            if(x[j] != x[L-j-1]) flag = false;
        }

        if(flag){
            ans = i*i*i;
        }
    }

    cout << ans << endl;
    return 0;
}