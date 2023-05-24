#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int N=8;
    char c;
    int x,y;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> c;
            if(c=='*'){
                y=N-i+1;
                x=j;
            }
        }
    }

    string st = " abcdefgh";
    string num = " 12345678";

    cout << st[x] << num[y] << endl;
    return 0;
}