#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int N = 8;
    string S;
    cin >> S;

    int x=-1,y=-1;
    for(int i = 0; i < N; i++){
        char c = S[i];
        if(c == 'B' && x < 0){
            x = i;
        }else if(c == 'B' && y < 0){
            y = i;
        }
    }

    if(x%2 == y%2){
        cout << "No" << endl;
        return 0;
    }

    x = -1;
    y = -1;
    int z = -1;
    for(int i = 0; i < N; i++){
        char c = S[i];

        if(c == 'R' && x < 0){
            x = i;
        }else if(c == 'R'){
            y = i;
        }else if(c == 'K'){
            z = i;
        }
    }

    if(x < z && z < y){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}