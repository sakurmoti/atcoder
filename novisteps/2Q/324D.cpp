#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    string S; cin >> S;

    sort(ALL(S));

    int ans = 0;
    for(ll x = 0; x*x <= 1e13; x++){
        stringstream ss;
        ss << setw(N) << setfill('0') << x*x;
        string y = ss.str();
        // cout << y << endl;

        sort(ALL(y));

        if(S == y){
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}