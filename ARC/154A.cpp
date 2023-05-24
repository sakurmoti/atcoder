#include <bits/stdc++.h>
using namespace std;

long long MODULO = 998'244'353;
long long mMODULO = 1e9 - MODULO;

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

int main(){
    int N;
    cin >> N;

    string A,B;
    cin >> A >> B;

    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    //A+Bが一定なのでA+B=Sとおく
    //このときA*B = A*(S-A) = -A^2 + SA = -(A - S/2)^2 + (S/2)^2と平方完成できる
    //ゆえにグラフからAのとりうる最大値or最小値にするとA*Bを最小化できることがわかる
    long long ans = 0;
    for(int i = 0; i < N; i++){
        int a = A.at(i) - '0';
        int b = B.at(i) - '0';

        if(a < b){
            char tmp = A.at(i);
            A.at(i) = B.at(i);
            B.at(i) = tmp;
        }
    }

    //Aのmodをとる
    long long AA = 0;
    for(int i = 0; i < A.size(); i++){
        long long a = A.at(i) - '0';
        a = a*powM(10, i, MODULO);

        AA += (a%MODULO);
        AA %= MODULO;
    }

    //cout << AA << endl;

    
    //Bのmodをとる
    long long BB = 0;
    for(int i = 0; i < B.size(); i++){
        long long b = B.at(i) - '0';
        b *= powM(10, i, MODULO);

        BB += (b%MODULO);
        BB %= MODULO;
    }

    //cout << BB << endl;

    cout << (AA*BB)%MODULO << endl;
    return 0;
}