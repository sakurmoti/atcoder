#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<string> S(N);
    vector<int> A(N);
    int idx = 0;
    int buf = 1e9;
    for(int i = 0; i < N; i++){
        cin >> S[i] >> A[i];

        if(A[i] <= buf){
            idx = i;
            buf = A[i];
        }
    }

    for(int i = 0; i < N; i++){
        int j = (idx+i) % N;
        cout << S[j] << endl;
    }

    
    return 0;
}