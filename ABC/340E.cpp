#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

#include <atcoder/all>
using namespace atcoder;

using S = ll;
using F = ll;
// 今回区間の要素の総積を必要としないのでとりあえず最小値を設定
S op(S a, S b){return min(a,b);}
S e(){return (int)2e9;}

S mapping(F f, S x){return x+f;}
F composition(F f, F g){return f+g;}
F id(){return 0;}

int main(){
    int N,M; cin >> N >> M;
    vector<ll> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    lazy_segtree<S, op, e, F, mapping, composition, id> seg(A);
    for(int i = 0; i < M; i++){
        int x; cin >> x;
        ll ball = seg.get(x);
        int k = ball/N;
        int t = ball%N;

        seg.set(x, 0);

        seg.apply(0, N, k);
        if(x + t+1 <= N){
            seg.apply(x+1, x+t+1, 1);
        }else{
            seg.apply(x+1, N, 1);
            seg.apply(0, x+t+1-N, 1);
        }
    
    }

    for(int i = 0; i < N; i++){
        cout << seg.get(i) << " ";
    }
    
    return 0;
}