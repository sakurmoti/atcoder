#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;

    int keta = S.size();
    for(int i = 3; i <= 9; i++){
        if(keta <= i){
            for(int j = 0; j < keta; j++){
                if(j < 3) cout << S[j];
                else cout << "0";
            }

            return 0;
        }
    }

    return 0;
}