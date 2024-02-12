#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

#include <atcoder/all>
using namespace atcoder;

int op(int a, int b){return min(a,b);}
int e(){return 0;}

int main(){
    int N,Q; cin >> N >> Q;

    segtree<int, op, e> seg(N);
    while(Q--){
        int c; cin >> c;

        if(c==1){
            int pos,x;
            cin >> pos >> x;
            seg.set(pos, x);

        }else{
            int l,r;
            cin >> l >> r;

            cout << seg.prod(l,r) << endl;
        }
    }
    return 0;
}