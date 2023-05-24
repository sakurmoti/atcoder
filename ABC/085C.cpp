#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,Y;
    cin >> N >> Y;

    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            //cout << 1000*i + 5000*j + 10000*k << endl;
            if(i+j <= N && 1000*i + 5000*j + 10000*(N-i-j) == Y){
                cout << N-i-j << " " << j << " " << i << endl;
                return 0;
            }
        }
    }
        
    cout << "-1 -1 -1"<< endl;
    
    return 0;
}