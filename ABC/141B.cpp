#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string S;
    cin >> S;
    
    string even = "RUD";
    string odd = "LUD";
    for(int i = 0; i < S.size(); i++){
        char c = S[i];
        if(c == 'U' || c == 'D'){
            continue;
        }

        if((i+1)%2 == 0){
            if(c=='R'){
                cout << "No" << endl;
                return 0;
            }
        }else{
            if(c == 'L'){
                cout << "No" << endl;
                return 0;
            }
        }

    }

    cout << "Yes" << endl;
    return 0;
}