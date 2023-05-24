#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,X;
    cin >> N >> X;
    
    int a;
    for(int i = 0; i < N; i++){
        cin >> a;
        if(a == X){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}