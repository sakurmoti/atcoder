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

        }else{
            if(table.empty()){
                cout << -1 << endl;
            
            }else{
                //x以上の最小値
                auto itr = table.lower_bound(x);

                //x以下の最大値
                auto itr2 = itr;
                if(itr2 != table.begin()) itr2--;

                cout << min(abs(x - *itr), abs(x - *(itr2)) ) << endl;
            }

        }
    }
    return 0;
}