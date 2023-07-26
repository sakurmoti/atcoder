#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    vector<int> A(N);
    for(auto &v : A) cin >> v;

    ll sum = 0;
    map<int, int> cnt;
    for(int i = 0; i < N; i++){
        sum += A[i];
        cnt[A[i]]++;
    }

    int Q; cin >> Q;
    for(int i = 0; i < Q; i++){
        ll B,C;
        cin >> B >> C;

        sum -= (B*cnt[B]);
        sum += (C*cnt[B]);

        cnt[C] += cnt[B];
        cnt[B] = 0;

        cout << sum << endl;
    }
    return 0;
}