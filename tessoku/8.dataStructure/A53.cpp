#include <bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> que;

    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        int cmd;
        cin >> cmd;

        if(cmd == 1){
            int x;
            cin >> x;

            que.push(x);
        
        }else if(cmd == 2){
            cout << que.top() << endl;
        
        }else{
            que.pop();
        }
    }
    return 0;
}