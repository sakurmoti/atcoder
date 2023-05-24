#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long N,A,B;
    cin >> N >> A >> B;
    
    N = N - A*(N/A);
    cout << N << endl;
    return 0;
}