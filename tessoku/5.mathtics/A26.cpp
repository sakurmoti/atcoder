#include <bits/stdc++.h>
using namespace std;

void solve(){
    int X;
    cin >> X;

    for(int i = 2; i*i <= X; i++){
        if(X%i == 0){
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
    return;
}

int main(){
    int Q;
    cin >> Q;

    for(int q = 0; q < Q; q++){
        solve();
    }

    return 0;
}