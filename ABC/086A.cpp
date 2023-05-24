#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    
    bool flag=true;
    if(a%2==0 || b%2==0){
        flag = false;
    }

    if(flag) cout << "Odd" << endl;
    else cout << "Even" << endl;
    return 0;
}