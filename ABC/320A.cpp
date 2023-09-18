#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int A,B;
    cin >> A >> B;
    int C = 1;
    for(int i = 0; i < B; i++){
        C *= A;
    }
    int D = 1;
    for(int i = 0; i < A; i++){
        D *= B;
    }

    cout << C + D << endl;
    return 0;
}