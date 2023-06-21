#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    string S; cin >> S;
    
    //RとGを決めたとき、Bは二分探索で求められそう
    set<int> R,G,B;
    ll r=0,g=0,b=0;
    for(int i = 0; i < N; i++){
        if(S[i]=='R'){
            R.insert(i);
            r++;
        }
        if(S[i]=='G'){
            G.insert(i);
            g++;
        }
        if(S[i]=='B'){
            B.insert(i);
            b++;
        }
    }

    ll ans = r*g*b;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            int k = 2*j - i;
            if(N <= k) continue;

            if(S[i] != S[j] && S[j] != S[k] && S[k] != S[i]) ans--;
            // cout << ans << endl;
        }
    }

    cout << ans << endl;
    return 0;
}