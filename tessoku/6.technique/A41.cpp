#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    string S;
    cin >> S;

    for(int i = 0; i < N; i++){
        string subS = S.substr(i, 3);

        if(subS == "RRR" || subS == "BBB"){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}