#include <bits/stdc++.h>
using namespace std;

int main(){
    long long X,Y;
    cin >> X >> Y;

    int count=0;
    for(long long i = X; i <= Y; i*=2){
        count++;
        //cout << i << endl;
    }

    cout << count << endl;

    return 0;
}