#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//imos法による解答 O(N+max(T))
int main(){
    int N,W;
    cin >> N >> W;

    int M = 1e6;
    vector<ll> imos(M, 0);
    for(int i = 0; i < N; i++){
        int S,T,P;
        cin >> S >> T >> P;    

        imos[S]+=P;
        imos[T]-=P;
    }

    ll maxi = -1;
    for(int i = 0; i < M-1; i++){
        imos[i+1] += imos[i];
        maxi = max(maxi, imos[i+1]);
    }
    maxi = max(maxi, imos[0]);

    if(maxi <= W){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }



    return 0;
}