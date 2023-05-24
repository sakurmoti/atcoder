#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;

    vector<long long> A(N+1);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
        A[i] %= K;
        if(A[i] < 0) A[i] += K;
    }

    //A[i]の部分和を計算しておく
    //これにより[3,7]の総和などはsumA[7] - sumA[3 - 1]のO(1)で求められる
    vector<long long> sumA(N+1, 0);
    sumA[1] = A[1];
    for(int i = 2; i <= N; i++){
        sumA.at(i) = sumA.at(i-1) + A.at(i);
    }


    int Q,L,R;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        cin >> L >> R;

        //K個に整数cを足すのでXの総和は c*Kずつ変化する
        //つまりXの総和がKの倍数である必要がある
        long long sum = sumA.at(R) - sumA.at(L-1);
        if(sum % K != 0){
            cout << "No" << endl;
            continue;

        }else{
            //また、あるK個を取ったときの総和がKの倍数でないと最初の一手がない
            bool flag = false;
            for(int i = 0; L+i+K <= R; i++){
                long long sum2 = sumA.at(L+i+K) - sumA.at(L+i-1);
                if(sum2 % K == 0){
                    flag = true;
                }
            }
            
            if(flag) cout << "Yes" << endl;

        }
    }
    return 0;
}