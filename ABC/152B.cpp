#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;

    string A;
    string B;
    for(int i = 0; i < a; i++){
        A += '0' + b;
    }

    for(int j = 0; j < b; j++){
        B += '0' + a;
    }

    cout << min(A,B) << endl;
    return 0;
}