#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int N;
    string S;
    cin >> N >> S;
    int x=-1,y=0,z=0;
    for(int i = 0; i < N; i++){
        if(S[i] == '|'){
            if(x < 0) x = i;
            else z = i;
        }else if(S[i] == '*'){
            y = i;
        }
    }

    if(x <= y && y <= z) cout << "in" << endl;
    else cout << "out" << endl;
    return 0;
}