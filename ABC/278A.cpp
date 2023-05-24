#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;

    queue<int> A;
    int a;
    for(int i = 0; i < N; i++){
        cin >> a;
        A.push(a);
    }

    for(int i = 0; i < K; i++){
        A.pop();
        A.push(0);
    }

    int size = A.size();
    for(int i = 0; i < size; i++){
        cout << A.front();
        A.pop();

        if(i != size) cout << " ";
        else cout << endl;
    }
    return 0;
}