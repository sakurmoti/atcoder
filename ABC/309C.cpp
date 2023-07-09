#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N,K;
    cin >> N >> K;

    vector<pair<ll, ll>> m(N);
    ll sum = 0;
    for(int i = 0; i < N; i++){
        cin >> m[i].first >> m[i].second;
        sum += m[i].second;
    }

    sort(m.begin(), m.end());

    if(sum <= K){
        cout << 1 << endl;
        return 0;
    }

    ll day = 0;
    for(int i = 0; i < N; i++){
        day = m[i].first+1;
        sum -= m[i].second;

        // cout << sum << endl;
        if(sum <= K){
            cout << day << endl;
            return 0;
        }
    }
    return 0;
}