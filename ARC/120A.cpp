#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N;
    cin >> N;

    vector<long long> A(N);
    for(long long i = 0; i < N; i++){
        cin >> A.at(i);
    }

    //sumA[i]はi番目までのAの和(1-index)　つまり累積和
    //maxA[i]はi番目まで見たときのAの最大値(1-index)
    vector<long long> sumA(N+1,0), maxA(N+1,0);
    for(long long i = 0; i < N; i++){
        sumA.at(i+1) = sumA.at(i) + A.at(i);
        maxA.at(i+1) = max(maxA.at(i), A.at(i));

        //printf("sumA[%d] = %d\n", i+1, sumA[i+1]);
    }

    long long temp=0;
    for(long long i = 1; i <= N; i++){
        /*a[i]にmax(A)を足すので次のmax(A)は必ずa[i]+max(A)になる
        これを繰り返すと例えば
        a[1] = (A[0] + max(A)) + A[1]
        a[2] = ( (A[0] + max(A)) + A[1] ) + A[2]となるので
        累積和を先に求めておけば計算量が減らせる。
        
        a[k] = (Σ_i->k A[i]) + max(A) = sumA[k] + maxA[k]
        これをすべて足すのでf(a[m]) = (Σ_i->m A[k]) = m*a[0] + (m-1)*a[1] + ... + 1*a[m] + m*maxA[k]
        */
        temp += sumA.at(i);
        long long ans = temp + i * maxA.at(i);

        cout << ans << endl;
    }
    return 0;
}