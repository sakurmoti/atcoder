#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    vector<int> A(N, M);
    for(int i = 0; i < M; i++){
        int a;
        cin >> a;
        a--;

        A[a]--;
    }

    for(int i = 0; i < N; i++){
        cout << A[i] << endl;
    }

    return 0;
}