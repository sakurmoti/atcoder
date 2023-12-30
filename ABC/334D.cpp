#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,Q; cin >> N >> Q;
    vector<ll> R(N+1, -1);
    for(int i = 1; i <= N; i++){
        cin >> R[i];
    }

    sort(ALL(R));

    vector<ll> csum(N+1, 0);
    for(int i = 1; i <= N; i++){
        csum[i] = csum[i-1] + R[i];
    }

    while(Q--){
        ll X; cin >> X;

        cout << distance(csum.begin(), prev(upper_bound(ALL(csum), X))) << endl;
    }
    return 0;
}