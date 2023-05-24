#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B;
    cin >> A >> B;

    for(int i = 0; i < 10000; i++){
        if( (int)(i*0.08) == A && (int)(i*0.1) == B){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}