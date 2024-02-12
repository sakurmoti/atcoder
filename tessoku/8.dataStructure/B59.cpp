#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

#include <atcoder/all>
using namespace atcoder;

int main(){
    int N; cin >> N;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    fenwick_tree<int> fw(N+1);
    ll ans = 0;
    for(int i = 0; i < N; i++){
        fw.add(A[i], 1);

        ans += fw.sum(A[i]+1, N+1);
    }

    cout << ans << endl;
    return 0;
}