#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    vector<ll> A(N);
    for(auto &_v : A) cin >> _v;
    
    for(int i = 0; i < N-1; i++){
        ll s,t;
        cin >> s >> t;

        A[i+1] += (A[i]/s) * t;
    }

    cout << A[N-1] << endl;
    return 0;
}