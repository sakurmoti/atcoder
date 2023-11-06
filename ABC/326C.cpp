#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,M; cin >> N >> M;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;
    sort(ALL(A));

    int ans = 0;
    for(int i = 0; i < N; i++){
        int r = A[i];
        int l = A[i]+M;

        int idx = lower_bound(ALL(A), l) - A.begin();

        // printf("[%d, %d] : %d\n",i, idx, idx-i);
        ans = max(ans, idx-i);
    }
    cout << ans << endl;
    return 0;
}