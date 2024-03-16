#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    ll X; cin >> X;

    if(X > 0) cout << (X+9)/10 << endl;
    else cout << X/10 << endl;
    return 0;
}