#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

#include <atcoder/all>
using namespace atcoder;

int main(){
    int N,Q; cin >> N >> Q;
    fenwick_tree<int> fw(N+1);

    while(Q--){
        int c; cin >> c;

        if(c==1){
            int pos,x;
            cin >> pos >> x;
            int pre = fw.sum(pos, pos+1);
            fw.add(pos, x-pre);

        }else{
            int l,r;
            cin >> l >> r;
            cout << fw.sum(l,r) << endl;

        }
    }
    return 0;
}