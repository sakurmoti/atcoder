#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N;
    cin >> N;

    long long c3 = N/3;
    long long c5 = N/5;
    long long c15 = N/15;

    cout << c3 + c5 - c15 << endl;
    return 0;
}