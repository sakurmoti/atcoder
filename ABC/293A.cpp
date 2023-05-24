#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    string S;
    cin >> S;

    for(int i = 0; (2*i)+1 < S.size(); i++){
        swap(S.at((2*i)+1), S.at(2*i));
    }

    cout << S << endl;
    return 0;
}