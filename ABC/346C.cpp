#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    ll N,K; cin >> N >> K;
    vector<ll> A(N);
    for(auto &_v : A) cin >> _v;

    ll sub = 0;
    set<int> st;
    for(int i = 0; i < N; i++){
        if(A[i] <= K && !st.contains(A[i])){
            sub += A[i];
            st.insert(A[i]);
        }
    }

    ll all = ( (1 + K) * K) / 2;
    // cout << all << " " << sub << endl;
    cout << all - sub << endl;
    return 0;
}