#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    vector<ll> A(N);
    for(auto &_v : A) cin >> _v;

    ll cnt = 0;
    ll m = 0;
    for(int i = 0; i < N; i++){
        cnt += A[i];
        if(cnt < 0){
            m = min(m, cnt);
        }
    }

    cout << cnt-m << endl;
    return 0;
}