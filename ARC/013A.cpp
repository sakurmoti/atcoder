#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M,L;
    cin >> N >> M >> L;
    int P,Q,R;
    cin >> P >> Q >> R;

    int ans = 0;
    vector<int> order = {P,Q,R};
    sort(order.begin(), order.end());
    do{
        // for(auto &_v : order) cout << _v << ' ';
        // cout << endl;
        int x = order[0];
        int y = order[1];
        int z = order[2];

        ans = max(ans, (N/y)*(M/x)*(L/z) );

    }while(next_permutation(order.begin(), order.end()));
    cout << ans << endl;
    return 0;
}