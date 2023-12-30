#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    // 3倍しても2で割れる回数は変わらない
    ll ans = 0;
    for(int i = 0; i < N; i++){
        while(A[i]%2 == 0){
            ans++;
            A[i] /= 2;
        }
    }

    cout << ans << endl;
    return 0;
}