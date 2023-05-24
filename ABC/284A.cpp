#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<string> S(N);
    for(int i = 0; i < N; i++){
        cin >> S.at(i);
    }

    for(int i = N-1; i >= 0; i--){
        cout << S.at(i) << endl;
    }
    return 0;
}