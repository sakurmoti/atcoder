#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a,b,c;
    cin >> a >> b >> c;

    //操作によってa,b,cの総和はかわらない
    if(a+b+c == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}