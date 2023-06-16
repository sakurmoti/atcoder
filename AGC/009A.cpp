#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<ll> A(N),B(N);
    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i];
    }

    //Anから順に決めていくしかない
    ll cnt = 0; //何回ボタンが押されたか
    for(int i = N-1; i >= 0; i--){
        A[i] += cnt;
        if(A[i]%B[i] != 0) cnt += (B[i] - (A[i]%B[i]));
        // printf("cnt=%lld, A[i]=%lld, B[i]=%lld\n",cnt,A[i],B[i]);
    }

    cout << cnt << endl;
    return 0;
}
