#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;

    reverse(S.begin(), S.end());

    int ans = 0;
    for(int i = 0; i < S.size(); i++){
        if(S.at(i) == '1'){
            ans += (1 << i);
        }
    }
    cout << ans << endl;
    return 0;
}