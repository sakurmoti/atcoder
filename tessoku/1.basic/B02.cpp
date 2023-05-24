#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B;
    cin >> A >> B;

    bool flag = false;
    for(int i = A; i <= B; i++){
        if(100 % i == 0){
            flag = true;
        }
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}