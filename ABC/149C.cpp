#include <bits/stdc++.h>
using namespace std;

int main(){
    int X;
    cin >> X;

    if(X==1 || X==2){
        cout << X << endl;
        return 0;
    }

    for(int p = X; p < X+100; p++){
        bool flag = true;

        for(int i = 2; i < p; i++){
            if(p%i == 0){
                flag = false;
                break;
            }
        }

        if(flag){
            cout << p << endl;
            break;
        }
    }
    return 0;
}