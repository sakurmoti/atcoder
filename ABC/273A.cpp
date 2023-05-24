#include <bits/stdc++.h>
using namespace std;

int fab(int x){
    if(x == 0) return 1;
    
    return fab(x-1)*x;
}

int main(){
    int N;
    cin >> N;

    cout << fab(N) << endl;
    return 0;
}