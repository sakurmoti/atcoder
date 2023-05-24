#include <bits/stdc++.h>
using namespace std;

queue<string> Queue;

void query(){
    int q;
    cin >> q;

    if(q == 1){
        string x;
        cin >> x;

        Queue.push(x);
    
    }else if(q == 2){
        cout << Queue.front() << endl;
    
    }else{
        Queue.pop();
    }
}

int main(){
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        query();
    }
    return 0;
}