#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    long long A,B;
    cin >> A >> B;

    if(A==B){
        cout << 0 << endl;
        return 0;
    }

    long long ans=0;
    while(A != B){
        if(A < B){
            long long tmp = B/A;
            if(tmp!=1) tmp--;
            B -= (A*tmp);
            ans += tmp;
            
        }else{
            long long tmp = A/B;
            if(tmp!=1) tmp--;
            A -= (B*tmp);
            ans += tmp;

        }

        //cout << A << " " << B << endl;
    }
    
    cout << ans << endl;
    return 0;
}