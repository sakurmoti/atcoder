#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

int main(){
    int Q;
    cin >> Q;

    deque<int> S;
    S.push_back(1);
    mint ans = 1;

    int cmd,x;
    for(int q = 0; q < Q; q++){
        cin >> cmd;

        if(cmd == 1){
            cin >> x;
            S.push_back(x);

            ans = ans*10 + x;

        }else if(cmd == 2){
            ans -= mint(10).pow(S.size()-1) * S.front();
            S.pop_front();

        }else if(cmd == 3){
            cout << ans.val() << endl;
        }
    }
    return 0;
}