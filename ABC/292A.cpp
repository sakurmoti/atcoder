#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    string S;
    cin >> S;

    for(int i = 0; i < S.size(); i++){
        if(!isupper(S.at(i))){
            S.at(i) += ('A'-'a');
        }
    }
    cout << S << endl;
    return 0;
}