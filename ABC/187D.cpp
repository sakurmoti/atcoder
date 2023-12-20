#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    vector<ll> A(N),B(N);
    ll Aoki = 0, Takahashi = 0;
    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i];
        Aoki += A[i];
    }

    // Takahasi - Aoki > 0を達成する最小の演説数
    // ある街で演説すればTakahashi += (A+B), aoki -= A[i]になる
    // つまり2*A + Bだけ変化する
    vector<pair<ll, int>> D(N);
    for(int i = 0; i < N; i++){
        D[i].first = 2*A[i] + B[i];
        D[i].second = i;
    }
    sort(RALL(D));

    int ans = 0;
    while(Takahashi <= Aoki){
        int idx = D[ans].second;
        Aoki -= A[idx];
        Takahashi += A[idx] + B[idx];
        ans++;

        // fprintf(stderr, "Takahashi=%d, Aoki=%d\n", Takahashi,Aoki);
    }

    cout << ans << endl;
    return 0;
}