#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    vector<int> A(N+1);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }

    //しゃくとり
    ll ans = 0;
    int r = 1;
    for(int l = 1; l <= N; l++){
        if(r < l) r = l;
        // printf("#1 (l,r) = (%d,%d)\n",l,r);
        while(r+1 <= N && A[r] < A[r+1]){
            r++;
            // printf("#2 (l,r) = (%d,%d)\n",l,r);
        }
        //a[l]から始まるもので条件を満たす個数は(r-l+1)
        ans += (r-l+1);
    }

    cout << ans << endl;
    return 0;
}