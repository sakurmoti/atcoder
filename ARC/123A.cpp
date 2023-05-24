#include <bits/stdc++.h>
using namespace std;

int main(){
    long long A1,A2,A3;
    cin >> A1 >> A2 >> A3;

    long long ans;
    if(2*A2 < A1+A3){
        long long temp = (A1+A3) - 2*A2;
        if(temp%2 == 0){
            ans = temp/2;
        }else{
            ans = temp/2 + 2;
        }
        
    }else{
        ans = 2*A2 - (A1+A3);
    }
    

    cout << ans << endl;
    return 0;
}