#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N,K;
    cin >> N >> K;

    //最低(N-1)+(N-1)回 = 2N-2回の移動する
    long long a = 2*N - 2;

    long long count = K - a;
    if(count < 0){
        cout << "No" << endl;
    
    }else{
        if(count%2 == 0){
            //残り回数が偶数ならその場を往復すればok
            cout << "Yes" << endl;
        
        }else{
            cout << "No" << endl;
        
        }
    }

    return 0;
}