#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string S; cin >> S;

    string alpha = "ABCDEFG";
    for(int i = 0; i < 7; i++){
        bool flag = true;
        for(int j = 0; j < 3; j++){
            if(S[j] != alpha[(i + 2*j)%7]){
                flag = false;
            }
        }

        if(flag){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}