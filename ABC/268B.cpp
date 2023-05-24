#include <bits/stdc++.h>
using namespace std;

int main(){
    string S,T;
    cin >> S >> T;

    bool flag = true;
    if(S.size() > T.size()) flag = false;
    
    for(int i = 0; i < S.size() && flag; i++){
        if(S.at(i) != T.at(i)){
            flag = false;
        }
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}