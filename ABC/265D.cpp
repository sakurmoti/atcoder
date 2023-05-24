#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N,P,Q,R;
    cin >> N >> P >> Q >> R;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A.at(i);

    //累積和を先に求める。sum[0]=0, sum[i]はA[0]~A[i-1]の総和とする
    //高校数学のSn+1 - Sn = an+1を利用するイメージ
    vector<long long> sum(N+1);
    sum[0] = 0;
    for(int i = 1; i <= N; i++){
        sum[i] += sum[i-1] + A[i-1];
    }

    /*これにより、Sy-Sx=P, Sz-Sy=Q, Sw-Sz=Rを満たすx,y,z,wを見つければよくなった
    A>0より累積和は単調増加のため、Sy-Sx=Pを満たすyは Sy = Sx + Pをyについて二分探索すればよい
    同様にz,wを求めるが、xは全探索で決める。するとO(NlogN)で求めることができる*/
    


    return 0;
}