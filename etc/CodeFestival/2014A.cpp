#include <bits/stdc++.h>
using namespace std;

int main(){
    int A;
    cin >> A;

    string ans="NO";
    for(int i = 1; i <= A; i++){
        if(i*i*i == A){
            ans = "YES";
            break;
        }
    }

    cout << ans << endl;
    return 0;
}