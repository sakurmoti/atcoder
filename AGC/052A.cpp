#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int N; cin >> N;
    vector<string> S(3); //0をN個、1をN個含む2Nの文字列
    for(int i = 0; i < 3; i++){
        cin >> S[i];
    }

    for(int i = 0; i < N; i++) cout << "0";
    for(int i = 0; i < N; i++) cout << "1";
    cout << "0" << endl;
}

int main(){
    int T; cin >> T;
    for(int i = 0; i < T; i++) solve();
    return 0;
}