#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    string S; cin >> S;
    bool f = false;
    if(S[0] == '<' && S[S.size()-1] == '>'){
        f = true;
        for(int i = 1; i < S.size()-1; i++){
            if(S[i] != '='){
                f = false;
            }
        }
    }

    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}