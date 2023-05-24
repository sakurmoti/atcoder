#include <bits/stdc++.h>
using namespace std;

constexpr int MODULO = 1e9 + 7;

int main(){
    int a,b;
    cin >> a >> b;

    bitset<32> B(b);
    vector<long long> A(32, a);
    //A[0]にはa^1, A[1]にはa^2, A[2]にはa^4, A[3]=a^8...が入る
    for(int i = 1; i < 32; i++){
        A.at(i) = (A.at(i-1) * A.at(i-1)) % MODULO;
        //cout << A.at(i-1) << endl;
    }

    long long ans=1;
    for(int i = 0; i < 32; i++){
        if(B.test(i)){
            ans *= A.at(i);
            ans %= MODULO;
        }
    }

    cout << ans << endl;

    return 0;
}