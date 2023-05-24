#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    //2^10 = 1024 ~= 1000
    //2^30 ~= 1000^3 = 10^9
    //2*10^9
    int ans = 1;
    for(int i = 0; i < N; i++){
        ans *= 2;
    }

    cout << ans << endl;
    return 0;
}