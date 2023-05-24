#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;

    int count=0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(1 <= K-(i+j) && K-(i+j) <= N){
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}