#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int Q; cin >> Q;

    priority_queue<ll, vector<ll>, greater<ll>> pque;
    ll plus = 0;
    for(int q = 0; q < Q; q++){
        int cmd; cin >> cmd;
        if(cmd == 1){
            int X; cin >> X;
            pque.push(X-plus); //plusのずれが起きないようにする
        }

        if(cmd == 2){
            int X; cin >> X;
            plus += X;
        }

        if(cmd == 3){
            cout << pque.top()+plus << endl;
            pque.pop();
        }
    }
    return 0;
}