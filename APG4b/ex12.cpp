#include <bits/stdc++.h>
using namespace std;

int main(void){
    string S;
    cin >> S;
    int ans=1;
    for(int i = 0; i < S.size(); i++){
        if(S[i] == '+'){
            ans++;
        }else if(S[i] == '-'){
            ans--;
        }
    }

    cout << ans << endl;
    return 0;
}