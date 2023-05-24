#include <bits/stdc++.h>
using namespace std;

long long GCD(long long X, long long Y){
    if(Y == 0) return X;
    return GCD(Y, X%Y);
}

long long LCM(int X, int Y){
    long long gcd = GCD(X,Y);
    return (X/gcd)*Y;
}

int main(){
    int A,B;
    cin >> A >> B;

    cout << LCM(A,B) << endl;
    return 0;
}