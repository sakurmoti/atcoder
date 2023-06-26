#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string S; cin >> S;
    ll K; cin >> K;

    for(int i = 0; i < S.size(); i++){
        if(S[i] != '1' && i+1 <= K){ //最初の1以外の数字で、そこに行くまでにKが超えていなければ
            cout << S[i] << endl;
            return 0;
        }
    }
    cout << 1 << endl;
    return 0;
}