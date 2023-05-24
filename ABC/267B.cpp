#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;

    if(S[0] == '1'){
        cout << "No" << endl;
        return 0;
    }

    //Tは左から順に全て倒れているかどうかを指す。倒れてるなら0
    string T = "1111111";
    if(S[6] == '0') T[0] = '0';
    if(S[3] == '0') T[1] = '0';
    if(S[7] == '0' && S[1] == '0') T[2] = '0';
    if(S[4] == '0' && S[0] == '0') T[3] = '0';
    if(S[8] == '0' && S[2] == '0') T[4] = '0';
    if(S[5] == '0') T[5] = '0';
    if(S[9] == '0') T[6] = '0';

    for(int i = 0; i < 7; i++){
        if(T[i] == '1'){
            for(int j = i+1; j < 7; j++){
                if(T[j] == '0'){
                    for(int k = j+1; k < 7; k++){
                        if(T[k] == '1'){
                            cout << "Yes" << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }

    cout << "No" << endl;
    return 0;
}