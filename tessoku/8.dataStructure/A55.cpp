#include <bits/stdc++.h>
using namespace std;

int main(){
    int Q;
    cin >> Q;

    set<int> table;
    for(int i = 0; i < Q; i++){
        int cmd, x;
        cin >> cmd >> x;

        if(cmd == 1){
            table.insert(x);
        
        }else if(cmd == 2){
            table.erase(x);
        
        }else{
            auto itr = table.lower_bound(x);
            
            if(itr == table.end()){
                cout << -1 << endl;
            
            }else{
                cout << *itr << endl;
            
            }
        }
    }
    return 0;
}