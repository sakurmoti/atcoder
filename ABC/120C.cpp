#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string S; cin >> S;
    int N = S.size();

    int r=0, b=0;
    for(int i = 0; i < N; i++){
        if(S[i] == '0') r++;
        else b++;
    }

    cout << 2*min(b,r) << endl;
    return 0;
}