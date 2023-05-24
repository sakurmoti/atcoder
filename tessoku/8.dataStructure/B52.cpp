#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,X;
    cin >> N >> X;

    vector<char> A(N+1);
    for(int i = 1; i <= N; i++){
        cin >> A.at(i);
    }

    queue<int> Queue;
    Queue.push(X);
    A.at(X) = '@';

    while(!Queue.empty()){
        int pos = Queue.front();
        Queue.pop();

        if(1 <= pos-1 && A.at(pos-1) == '.'){
            A.at(pos-1) = '@';
            Queue.push(pos-1);
        }

        if(pos+1 <= N && A.at(pos+1) == '.'){
            A.at(pos+1) = '@';
            Queue.push(pos+1);
        }
    }

    for(int i = 1; i <= N; i++){
        cout << A.at(i);
    }
    return 0;
}