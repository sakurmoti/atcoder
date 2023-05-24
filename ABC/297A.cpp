#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int N,D;
    cin >> N >> D;

    int T1,T2;
    cin >> T1;
    for(int i = 1; i < N; i++){
        cin >> T2;
        if(T2-T1 <= D){
            cout << T2 << endl;
            return 0;
        }
        T1 = T2;
    }
    cout << -1 << endl;
    return 0;
}