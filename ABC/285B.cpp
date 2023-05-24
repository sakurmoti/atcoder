#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    string S;
    cin >> S;

    for(int i = 1; i <= N-1; i++){
        int l=1;

        for(int j = 0; j < N; j++){
            if(N <= j+i) break;

            if(S.at(j) == S.at(j+i)){
                break;

            }else{
                l++;

            }
        }

        cout << l-1 << endl;
    }
    return 0;
}