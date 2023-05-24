#include <bits/stdc++.h>
using namespace std;

constexpr int MODULO = 1000000007;

int main(){
    int N;
    cin >> N;

    int ans;
    int pre = 1;
    int prepre = 1;
    for(int i = 3; i <= N; i++){
        ans = (pre + prepre);
        ans %= MODULO;
        prepre = pre;
        pre = ans;

    }
    cout << ans << endl;
    return 0;
}