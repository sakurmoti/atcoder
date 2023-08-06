#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    string S; cin >> S;
    bool A=false,B=false,C=false;
    for(int i = 0; i < N; i++){
        if(S[i] == 'A') A=true;
        if(S[i] == 'B') B=true;
        if(S[i] == 'C') C=true;

        if(A && B && C){
            cout << i+1 << endl;
            return 0;
        }
    }
    return 0;
}