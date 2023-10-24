#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    int N; cin >> N;
    string S; cin >> S;

    sort(S.begin(), S.end());

    ll dig = 1;
    for(int i = 0; i < N; i++){
        dig *= 10;
    }

    ll ans = 0;
    for(ll i = 0; i*i < dig; i++){
        string A;
        A.assign(N, '0');
        
        string B = to_string(i*i);
        int b = B.size();
        for(int j = 0; j < b; j++){
            A[j] = B[j];
        }

        sort(A.begin(), A.end());
        if(A == S){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}