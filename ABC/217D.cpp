#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int L; cin >> L;

    int Q; cin >> Q;
    set<int> cut = {0,L};
    for(int i = 0; i < Q; i++){
        int c,x;
        cin >> c >> x;

        if(c==1){
            cut.insert(x);
        }

        if(c==2){
            auto pre = prev(cut.lower_bound(x));
            auto nex = cut.lower_bound(x);

            cout << (*nex) - (*pre) << endl;
        }
    }
    return 0;
}