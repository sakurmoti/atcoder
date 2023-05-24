#include <bits/stdc++.h>
using namespace std;

long long powM(long long x, long long y, long long MODULO){
    const int MAX_BIT = 64;
    vector<long long> A(MAX_BIT, x);
    bitset<MAX_BIT> B(y);

    for(int i = 1; i < MAX_BIT; i++){
        A.at(i) = (A.at(i-1) * A.at(i-1)) % MODULO;
    }

    long long ret=1;
    for(int i = 0; i < MAX_BIT; i++){
        if(B.test(i)){
            ret *= A.at(i);
            ret %= MODULO;
        }
    }

    return ret;
}

long long division(long long x, long long y, long long MODULO){
    long long ret = x * powM(y, MODULO-2, MODULO);
    ret %= MODULO;
    return ret;
}

int main(){
    long long H,W;
    cin >> H >> W;

    int M = 1e9 + 7;

    //右にH-1回、下にW-1回移動すればよい
    //(H+W-2) Combination (H-1)
    long long a = 1;
    for(int i = 1; i <= H+W-2; i++){
        a = (a*i)%M;
    }

    long long b = 1;
    for(int i = 1; i <= H-1; i++){
        b = (b*i)%M;
    }
    for(int i = 1; i <= W-1; i++){
        b = (b*i)%M;
    }

    cout << division(a,b,M) << endl;
    return 0;
}