#include <bits/stdc++.h>
using namespace std;

int main(void){
    int Y;
    cin >> Y;

    if( (Y-2)%4 == 0) cout << Y << endl;
    else cout << Y + (4 - (Y-2)%4) << endl;

    return 0;
}