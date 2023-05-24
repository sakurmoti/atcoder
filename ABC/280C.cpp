#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;

    char t;
    for(int i = 1; i <= S.size()+1; i++){
        cin >> t;
        if(i == S.size()+1){
            cout << i << endl;
            break;
        }

        if(t == S.at(i-1)){
            continue;
        
        }else{
            cout << i << endl;
            break;
        }
    }


    return 0;
}