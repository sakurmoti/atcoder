#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;

    vector<int> A(N),B(N);
    for(int i = 0; i < N; i++) cin >> A.at(i);
    for(int i = 0; i < N; i++) cin >> B.at(i);

    //A.at(i)とB.at(i)の絶対値の差
    int diff = 0;
    for(int i = 0; i < N; i++){
        diff += abs(A.at(i)-B.at(i));
    }

    if(diff <= K){
        if((K-diff)%2 == 0){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;


    return 0;
}