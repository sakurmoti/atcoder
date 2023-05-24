#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int N,A,B;
    cin >> N >> A >> B;

    for(int i = 0; i < N; i++){
        int c;
        cin >> c;

        if(A+B == c){
            cout << i+1 << endl;
            return 0;
        }
    }
    
    return 0;
}