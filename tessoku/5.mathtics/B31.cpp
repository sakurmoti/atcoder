#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N;
    cin >> N;

    long long c3 = N/3;
    long long c5 = N/5;
    long long c7 = N/7;

    long long c15 = N/15;
    long long c35 = N/35;
    long long c21 = N/21;

    long long c105 = N/105;

    cout << (c3+c5+c7) - (c15+c35+c21) + c105 << endl;
    return 0;
}