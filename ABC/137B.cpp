#include <bits/stdc++.h>
using namespace std;

int main(){
    int K,X;
    cin >> K >> X;

    for(int i = X-K+1; i < X+K; i++){
        cout << i << " ";
    }
    return 0;
}