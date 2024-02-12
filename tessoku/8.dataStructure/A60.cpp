#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

#include <atcoder/all>
using namespace atcoder;

int op(int a, int b){return max(a,b);}
int e(){return 0;}

int main(){
    int N; cin >> N;
    vector<int> A(N+1, -1);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }

    segtree<int, op, e> seg(A);

    vector<int> ans(N+1, -1);
    for(int i = 1; i <= N; i++){
        int ok = -1;
        int ng = i;

        while(abs(ok-ng) >= 2){
            int mid = (ok + ng)/2;

            if(A[i] < seg.prod(mid, i)){
                ok = mid;
            }else{
                ng = mid;
            }
        }

        ans[i] = ok;
    }

    for(int i = 1; i <= N; i++){
        cout << ans[i] << " ";
    }
    return 0;
}