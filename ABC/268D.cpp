#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    vector<string> S(N),T(M);
    for(int i = 0; i < N; i++){
        cin >> S[i];
    }
    for(int i = 0; i < M; i++){
        cin >> T[i];
    }

    for(int i = 0; i < (2<<N); i++){
        cout << i << endl;
    }

}