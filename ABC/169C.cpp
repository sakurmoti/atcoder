#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll A; cin >> A;
    string B; cin >> B;
    
    // A*B = ans
    // 100*A*B = 100ans
    ll C = (B[0]-'0')*100 + (B[2]-'0')*10 + (B[3]-'0');
    cout << (A*C)/100 << endl;
    return 0;
}