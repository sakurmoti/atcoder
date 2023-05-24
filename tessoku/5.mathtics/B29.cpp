#include <bits/stdc++.h>
using namespace std;

//x^yをMODULOで割った値
long long powM(long long x, long long y, long long MODULO){
    const int MAX_BIT = 64; //long longが64bitなので
    vector<long long> A(MAX_BIT, x);
    bitset<MAX_BIT> B(y);

    for(int i = 1; i < MAX_BIT; i++){
        //A[0]にa^1, A[1]にa^1*a^1, A[2]にa^2 * a^2...
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

int main(){
    long long a,b;
    cin >> a >> b;

    cout << powM(a,b,1e9 + 7) << endl;;
    return 0;
}