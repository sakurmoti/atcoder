#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M,K;
    cin >> N >> M >> K;

    vector<ll> A(N+1),B(M+1);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }
    for(int i = 1; i <= M; i++){
        cin >> B[i];
    }

    //累積和+にぶたんで高速に求めればよい
    vector<ll> cmA(N+1,0), cmB(M+1,0);
    for(int i = 1; i <= N; i++){
        cmA[i] = cmA[i-1] + A[i];
    }
    for(int i = 1; i <= M; i++){
        cmB[i] = cmB[i-1] + B[i];
    }

    int ans = 0;
    for(int i = 0; i <= N; i++){
        int ok = 0;
        int ng = M+1;
        while(abs(ok-ng) >= 2){
            int mid = (ok+ng)/2;
            
            if(cmA[i] + cmB[mid] > K){
                ng = mid;
            }else{
                ok = mid;
            }
        }
        
        if(cmA[i] + cmB[ok] <= K) ans = max(ans, i+ok);
    }

    cout << ans << endl;
    return 0;
}