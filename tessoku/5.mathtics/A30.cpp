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
    int n,r;
    cin >> n >> r;
    
    int M = 1e9 + 7;

    long long a = 1;
    for(int i = 1; i <= n; i++){
        a *= i;
        a %= M;
    }

    long long b = 1;
    for(int i = 1; i <= r; i++){
        b *= i;
        b %= M;
    }
    for(int i = 1; i <= (n-r); i++){
        b *= i;
        b %= M;
    }

    cout << division(a,b,M) << endl;

    return 0;
}