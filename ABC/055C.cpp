#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N,M;
    cin >> N >> M;

    long long ans=0;

    if(N < M){
        ans = N;
        ans += (M-2*N)/4;
    
    }else{
        ans = (M/2);

    }

    cout << ans << endl;
    return 0;
}