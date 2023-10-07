#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string S; cin >> S;
    bool ans = true;
    for(int i = 1; i < S.size(); i+=2){
        if(S[i] == '1'){
            ans = false;
        }
    }

    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}