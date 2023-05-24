#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,X;
    cin >> N >> X;

    int p;
    for(int i = 0; i < N; i++){
        cin >> p;
        
        if(p == X){
            cout << i+1 << endl;
            break;
        }
    }


    return 0;
}