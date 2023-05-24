#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    string S;
    cin >> S;

    long long N;
    cin >> N;

    long long T = 0;
    long long bits = 1;
    for(int i = S.size()-1; i >= 0; i--){
        if(S[i] == '1') T += bits;
        bits *= 2;
    }
    bits/=2; //最後の余分をなくす

    if(N < T){
        cout << -1 << endl;
        return 0;
    }

    for(int i = 0; i < S.size(); i++){
        if(S[i] == '?'){
            //cout << bits << endl;
            if(T + bits <= N){
                T += bits;
            }
        }

        bits /= 2;

    }

    cout << T << endl;

    return 0;
}