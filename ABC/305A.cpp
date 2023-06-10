#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    int buf = N%5;
    if(buf <= 2){
        cout << N -buf << endl; 
    }else{
        cout << N+(5-buf) << endl;
    }
    return 0;
}