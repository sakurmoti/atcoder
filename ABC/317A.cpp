#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,H,X;
    cin >> N >> H >> X;

    for(int i = 0; i < N; i++){
        int P; cin >> P;
        if(H+P >= X){
            cout << i+1 << endl;
            break;
        }
    }

    return 0;
}