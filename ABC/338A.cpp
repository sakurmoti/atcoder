#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    string S; cin >> S;
    bool f1=false,f2=true;

    if(S[0] - 'a' < 0) f1 = true;

    for(int i = 1; i < S.size(); i++){
        if(S[i] - 'a' < 0) f2 = false;
    }

    if(f1 && f2) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}