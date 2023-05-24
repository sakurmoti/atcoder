#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    string S;
    cin >> S;

    for(int i = 0; i < S.size(); i++){
        if(S.at(i) - 'a' < 0){
            cout << i << endl;
            break;
        }
    }
    return 0;
}