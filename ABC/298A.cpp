#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int N;
    string S;
    cin >> N >> S;

    bool f1=false, f2=true;
    for(int i = 0; i < N; i++){
        if(S[i] == 'o') f1 = true;
        if(S[i] == 'x') f2 = false;
    }

    if(f1 && f2) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}