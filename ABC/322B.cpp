#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M; cin >> N >> M;
    string S,T; cin >> S >> T;

    int ans = 3;
    // 接頭辞
    bool atama = true;
    for(int i = 0; i < N; i++){
        if(S[i] != T[i]){
            atama = false;
        }
    }

    // 接尾辞
    bool last = true;
    for(int i = 0; i < N; i++){
        if(S[i] != T[M-N+i]){
            last = false;
        }
    }

    if(atama) ans -= 2;
    if(last) ans -= 1;

    cout << ans << endl;
    return 0;
}