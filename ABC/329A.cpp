#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    string S; cin >> S;
    for(int i = 0; i < S.size(); i++){
        cout << S[i];
        if(i != S.size()-1) cout << " ";
        else cout << endl;
    }
    return 0;
}