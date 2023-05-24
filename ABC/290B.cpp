#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int N,K;
    cin >> N >> K;

    string S;
    cin >> S;

    int cnt=0;
    string T;
    for(int i = 0; i < N; i++){
        if(S.at(i) == 'o' && cnt < K){
            T.push_back('o');
            cnt++;
        
        }else{
            T.push_back('x');
        }
    
    }

    cout << T << endl;
    return 0;
}