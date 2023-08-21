#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string S;
    cin >> S;

    for(int i = 0; i < S.size(); i++){
        char c = S[i];
        if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u'){
            cout << c;
        }
    }
    cout << endl;
    return 0;
}