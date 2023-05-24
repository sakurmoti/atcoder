#include <bits/stdc++.h>
using namespace std;

int main(){
    long long X;
    int K;

    cin >> X >> K;

    for(int i = 0; i < K; i++){
        
        //moduloはi = kの時に割る値。つまり10^k
        long long modulo = 10;
        for(int j = 1; j <= i; j++){
            modulo *= 10;
        }

        if(X % modulo < 5 * modulo/10){
            X -= (X % modulo);

        }else{
            X += (modulo - (X % modulo));

        }

        //if(X == 0) break;
        //cout << X << endl;
    }

    cout << X << endl;
    return 0;
}