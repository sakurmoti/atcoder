#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;

    int count = 0;
    char c;
    for(int i = 0; i < N; i++){
        cin >> c;
        if(c == '1'){
            count++;
        }
    }

    //{on,on},{on,off},{off,off}の反転があり得るが、これらは全てonの偶奇は変わらない
    if(K%2 == count%2){
        cout << "Yes" << endl;
    
    }else{
        cout << "No" << endl;
    
    }
    return 0;
}