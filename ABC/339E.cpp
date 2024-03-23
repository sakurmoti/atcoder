#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

constexpr int MAX_A = 500'010;
#include <atcoder/all>
using namespace atcoder;

using S = int;
S op(S a, S b){return max(a,b);}
S e(){return -1;}

int main(){
    int N,D; cin >> N >> D;
    vector<int> A(N+1);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }

    // dp[i] := 最後に採用したのがiのときの最大の長さ
    vector<int> dp(MAX_A, 0);
    segtree<S, op, e> seg(dp);

    for(int i = 1; i <= N; i++){
        S res = seg.prod(max(0, A[i]-D) , min(MAX_A, A[i]+D+1)) + 1;
        seg.set(A[i], res);
    }

    cout << seg.all_prod() << endl;
    return 0;
}