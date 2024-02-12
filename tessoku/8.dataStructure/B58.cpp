#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

#include <atcoder/all>
using namespace atcoder;

int op(int a, int b){return min(a,b);}
int e(){return (int)1e9;}

int main(){
    int N,L,R; cin >> N >> L >> R;
    
    segtree<int, op, e> seg(N);
    vector<int> X(N);
    for(int i = 0; i < N; i++){
        cin >> X[i];
    }

    vector<int> dp(N, 1e9);
    dp[0] = 0;
    seg.set(0, 0);
    for(int i = 1; i < N; i++){
        // X[i] + L <= k <= X[i] + R の区間にある足場なら移動可能
        int left_idx = lower_bound(ALL(X), X[i]-R) - X.begin();
        int right_idx = lower_bound(ALL(X), X[i]-L+1) - X.begin();

        // このとき、dp[i] = min(dp[left], dp[left+1], dp[left+2] ..., dp[right]) + 1
        // この区間の最小値をsegtreeで求めれば高速
        dp[i] = seg.prod(left_idx, right_idx) + 1;
        seg.set(i, dp[i]);
    }
    
    cout << dp[N-1] << endl;
    return 0;
}