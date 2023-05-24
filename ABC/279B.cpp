#include <bits/stdc++.h>
using namespace std;

int main(){
    string S,T;
    cin >> S >> T;

    string ans = "No";
    if(S.size() < T.size()){
    
    }else{
        for(int i = 0; i < S.size(); i++){
            if(S.substr(i, T.size()) == T){
                ans = "Yes";
                break;
            }
        }

    }

    cout << ans << endl;
    return 0;
}