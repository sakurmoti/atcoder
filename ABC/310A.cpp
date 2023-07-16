#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,P,Q;
    cin >> N >> P >> Q;
    vector<int> D(N);
    for(auto &v : D) cin >> v;
    
    sort(D.begin(), D.end());

    if(P < Q+D[0]) cout << P << endl;
    else cout << Q + D[0] << endl;
    return 0;
}