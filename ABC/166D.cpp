#include <bits/stdc++.h>
using namespace std;

int main(void){
    int X;
    cin >> X;

    for(int i = -200; i <= 200; i++){
        for(int j = -200; j <= 200; j++){
            if(pow(i,5) - pow(j,5) == X){
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    return 0;
}