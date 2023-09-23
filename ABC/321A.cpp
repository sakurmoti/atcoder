#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string S; cin >> S;
    bool ans = true;
    for(int i = 0; i < S.size()-1; i++){
        if(S[i] <= S[i+1]){
            ans = false;
        }
    }

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}