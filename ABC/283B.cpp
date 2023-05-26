#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> A(N);
    for(auto &v : A) cin >> v;

    int Q; cin >> Q;
    for(int i = 0; i < Q; i++){
        int cmd; cin >> cmd;

        if(cmd == 1){
            int k,x;
            cin >> k >> x;
            k--;

            A.at(k) = x;
        }

        if(cmd == 2){
            int k;
            cin >> k;
            k--;
            cout << A.at(k) << endl;
        }
    }

    return 0;
}