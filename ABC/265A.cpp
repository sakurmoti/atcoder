#include <bits/stdc++.h>
using namespace std;

int main(){
    int X,Y,N;
    cin >> X >> Y >> N;
    
    if(3*X > Y){
        //できるだけ3個セットで買う
        cout << Y*(N/3) + X*(N%3) << endl;
    }else{
        //1個ずつ買う
        cout << X*N;
    }
    return 0;
}