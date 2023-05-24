#include <bits/stdc++.h>
using namespace std;

int main(void){
    string S;
    cin >> S;

    bool flag = true;
    if(S.at(0) == 'A'){ //条件1
        
        //条件2
        int count=0;
        for(int i = 2; i <= S.size()-2; i++){
            if(S.at(i) == 'C') count++;
        }
        if(count != 1) flag = false;

        //条件3
        count = 0;
        for(int i = 0; i < S.size(); i++){
            if('A' <= S.at(i) && S.at(i) <= 'Z') count++;
        }
        if(count > 2) flag = false;
    }else{
        flag = false;
    }

    if(flag) cout << "AC" << endl;
    else cout << "WA" << endl;
    return 0;
}