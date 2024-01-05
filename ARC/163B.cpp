#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,M; cin >> N >> M;
    int L,R; cin >> L >> R;
    vector<int> A(N-2);
    for(auto &_v : A) cin >> _v;

    sort(ALL(A));

    int ans = 2e9;
    for(int l = 0; l < N; l++){
        int r = l+M-1;
        if(r >= N-2) break;

        // LをA[l]まで、RをA[r]まで上げる
        ans = min(ans, max(0, L-A[l]) + max(0, A[r]-R) );
        // fprintf(stderr, "l=%d, r=%d\n", l, r);
        // fprintf(stderr, "ans=%d\n", ans);
    }

    cout << ans << endl;
    return 0;
}