#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string S; cin >> S;
    S.insert(0, " ");

    if(S[1] == '1'){
        cout << "No" << endl;
        return 0;
    }

    vector<bool> all(7, false);
    if(S[7] == '0') all[0] = true;
    if(S[4] == '0') all[1] = true;
    if(S[2] == '0' && S[8] == '0') all[2] = true;
    if(S[1] == '0' && S[5] == '0') all[3] = true;
    if(S[3] == '0' && S[9] == '0') all[4] = true;
    if(S[6] == '0') all[5] = true;
    if(S[10] == '0') all[6] = true;

    for(int i = 0; i < 7; i++){
        for(int j = i+2; j < 7; j++){
            if(!all[i] && !all[j] && all[j-1]){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}