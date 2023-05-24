#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N,K;
    cin >> N >> K;
    
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    //1 << Nは1をNビット右シフトしたもの。つまり2^N
    for(int i = 0; i < (1 << N); i++){
        bitset<20> select(i); //iを二進数に直す。bitsetの大きさに変数は使えないことに注意
        
        int sum = 0;
        for(int j = 0; j < N; j++){
            if(select.test(j)){ //jが1なら
                sum += A.at(j); //加算
            }
        }

        if(sum == K){
            cout << "YES" << endl;
            return 0;
        }

    }

    cout << "NO" << endl;
    return 0;
}