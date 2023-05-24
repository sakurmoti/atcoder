#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;

    if(c < a){
        int buf = a;
        a = c;
        c = buf;
    }

    //a <= c
    if(a <= b && b <= c) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}