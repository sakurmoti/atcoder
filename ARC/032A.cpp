#include <bits/stdc++.h>
using namespace std;

int sum(int x){
    int ret;

    if(x==1) return 1;
    else ret = x + sum(x-1);

    return ret;
}


int main(){
    int n;
    cin >> n;

    bool flag=true;
    int X = sum(n);

    if(X == 1){
        flag = false;
    }

    for(int i = 2; i < X; i++){
        if(X%i == 0){
            flag = false;
            break;
        }
    }

    if(flag) cout << "WANWAN" << endl;
    else cout << "BOWWOW" << endl;

    return 0;
}