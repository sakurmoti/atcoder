#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B;
    cin >> A >> B;

    bitset<3> bitA(A);
    bitset<3> bitB(B);

    bitset<3> snuke;
    snuke = bitA | bitB;

    cout << snuke.to_ulong() << endl;
    return 0;
}