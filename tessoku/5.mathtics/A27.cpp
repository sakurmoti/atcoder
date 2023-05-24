#include <bits/stdc++.h>
using namespace std;

long long GCD(int X, int Y){
    if(Y == 0) return X;
    return GCD(Y, X%Y);
}

int main(){
    int A,B;
    cin >> A >> B;

    cout << GCD(A,B) << endl;
    return 0;
}