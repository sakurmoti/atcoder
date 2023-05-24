#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int N;
    cin >> N;

    string T[] = {"and", "not", "that", "the", "you"};
    for(int i = 0; i < N; i++){
        string S;
        cin >> S;

        for(int j = 0; j < 5; j++){
            if(S == T[j]){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}