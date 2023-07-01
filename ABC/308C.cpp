#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    vector<long double> A(N),B(N);
    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i];
    }

    vector<pair<long double, int>> ans(N);
    for(int i = 0; i < N; i++){
        if(A[i]==0) ans[i] = make_pair(1e10, (i+1));
        else ans[i] = make_pair(B[i]/A[i], (i+1));
    }

    sort(ans.begin(), ans.end());

    for(int i = 0; i < N; i++){
        cout << ans[i].second << " \n"[i==N-1];
    }
    return 0;
}