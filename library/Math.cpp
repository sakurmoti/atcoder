#include <bits/stdc++.h>
using namespace std;

//エラトステネスの篩 O(N*log(logN)) ~= O(N)
vector<int> Eratosthenes(int N){
    vector<bool> prime(N+1, true); //trueになっている添え字は素数

    for(int i = 0; i*i <= N; i++){
        if(i==0 || i==1) prime.at(i) = false;

        if(prime.at(i) == false){
            continue;
        
        }else{
            for(int j = 2; i*j <= N; j++){
                prime.at(i*j) = false;
            }

        }
    }

    vector<int> ret;
    for(int i = 0; i <= N; i++){
        if(prime.at(i)) ret.push_back(i);
    }

    return ret;
}

//最大公約数 ユークリッドの互除法 O(log(X+Y))
long long GCD(long long X, long long Y){
    if(Y == 0) return X;
    return GCD(Y, X%Y);
}

//最小公倍数 X*Y = GCD(X,Y)*LCM(X,Y)を利用 O(log(X+Y))
long long LCM(long long X, long long Y){
    long long gcd = GCD(X,Y);
    return (X/gcd)*Y;
}

//x^yをMODULOで割った値　繰り返し二乗法 O(logM)
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

// x÷yをMで割った値　フェルマーの小定理より「M が素数かつbとM が互いに素」のときMを法とすると x÷y = x*(y^(M-2))を利用
long long division(long long x, long long y, long long MODULO){
    long long ret = x * powM(y, MODULO-2, MODULO);
    ret %= MODULO;
    return ret;
}