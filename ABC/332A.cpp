#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,S,K;
    cin >> N >> S >> K;

    ll sum = 0;
    for(int i = 0; i < N; i++){
        int P,Q; cin >> P >> Q;

        sum += P*Q;
    }

    if(sum < S) sum += K;

    cout << sum << endl;
    return 0;
}