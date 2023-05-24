#include <bits/stdc++.h>
using namespace std;

int main(){
    int s;
    cin >> s;

    int ans=0;
    for(int i = 0; i < 3; i++){
        ans += s%10;
        s/=10;
    }

    cout << ans << endl;
    return 0;
}