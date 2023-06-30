#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int S,T;
    cin >> S >> T;

    int cnt = 0;
    for(int a = 0; a <= 100; a++){
        for(int b = 0; b <= 100; b++){
            for(int c = 0; c <= 100; c++){
                if(a+b+c <= S && a*b*c <= T){
                    cnt++;
                }
            }
        }
    }

    cout << cnt << endl;
    return 0;
}