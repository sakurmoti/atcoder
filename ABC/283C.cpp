#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;

    int count=0;
    for(int i = 0; i < S.size()-1; i++){
        if(S.at(i) == '0' && S.at(i+1) == '0'){
            count++;
            i++;
        }
    }
    cout << S.size() - count << endl;
    return 0;
}