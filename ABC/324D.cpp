#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    string S; cin >> S;

    sort(S.begin(), S.end());

    set<ll> ans;
    do{
        // for(auto &_v : S) cout << _v << ' ';
        // cout << endl;

        ll num = 0;
        ll dig = 1;
        for(int i = N-1; i >= 0; i--){
            num += dig*(S[i]-'0');
            dig *= 10;
        }

        ll sq = sqrt(num);
        for(int i = -10; i <= 10; i++){
            ll x = sq+i;
            if(x*x == num){
                cout << num << endl;
                ans.insert(num);
            }
        }

    }while(next_permutation(S.begin(), S.end()));

    cout << ans.size() << endl;
    return 0;
}