#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    string S; cin >> S;
    bool flag = true;
    for(int i = 0; i < S.size(); i++){
        if(S[i] == '|'){
            flag = !flag;
            continue;
        }
        if(flag) cout << S[i];
    }
    return 0;
}