#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    vector<ll> A(N);
    for(auto &v : A) cin >> v;

    //操作を行っても総和は変わらない
    //最終的には全ての値が平均になる必要がある
    ll sum = 0;
    for(int i = 0; i < N; i++){
        sum += A[i];
    }

    ll avg = sum/N; //余りが出るなら切り捨てなので、最終的な値はavgとavg+1になる
    ll modulo = sum%N; //avg+1の個数
    // printf("avg = %d, modulo = %d\n", avg, modulo);

    sort(A.begin(), A.end());

    ll ans = 0;
    for(int i = 1; i <= modulo; i++){
        //上からmodulo個選んでavg+1にする
        ans += abs(A[N-i] - (avg+1));
    }

    for(int i = 0; i < N-modulo; i++){
        ans += abs(A[i] - (avg));
    }

    cout << ans/2 << endl; //プラスに操作する分マイナスも操作しているから
    return 0;
}