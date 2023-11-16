#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,X; cin >> N >> X;
    vector<int> S(N);
    for(auto &_v : S) cin >> _v;

    int sum = 0;
    for(int i = 0; i < N; i++){
        if(S[i] <= X) sum += S[i];
    }

    cout << sum << endl;
    return 0;
}