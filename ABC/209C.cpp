#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;

int main(){
    int N; cin >> N;
    vector<int> C(N+1,0);
    for(int i = 1; i <= N; i++){
        cin >> C[i];
    }

    mint ans = 1;
    sort(C.begin(), C.end());
    for(int i = 1; i <= N; i++){
        ans = ans*(C[i]-(i-1));
    }
    
    cout << ans.val() << endl;
    return 0;
}