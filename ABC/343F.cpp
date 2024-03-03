#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

#include <atcoder/all>
using namespace atcoder;
using S = pair<pair<int, int>, pair<int, int>>; // 上位2つの値と個数を管理
S op(S a, S b){
    map<int, int, greater<int>> dict; // key : 値 , value : 個数
    dict[a.first.first] += a.first.second;
    dict[a.second.first] += a.second.second;
    dict[b.first.first] += b.first.second;
    dict[b.second.first] += b.second.second;

    // for(auto [k,v] : dict){
    //     printf("k : %d, v : %d\n", k, v);
    // }
    // printf("\n");

    pair<int, int> v1 = *dict.begin();
    pair<int, int> v2 = *next(dict.begin());
    return make_pair(v1, v2);
}

S e(){return make_pair(make_pair(0,0), make_pair(-1,0)); }

int main(){
    int N,Q; cin >> N >> Q;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    vector<S> init(N);
    for(int i = 0; i < N; i++){
        init[i].first = make_pair(A[i], 1);
        init[i].second = make_pair(0,0);
    }
    segtree<S, op, e> seg(init);
    while(Q--){
        int q; cin >> q;

        if(q == 1){
            int p,x; cin >> p >> x;
            p--;
            S v = make_pair(make_pair(x, 1), make_pair(0,0));
            seg.set(p, v);
        }

        if(q == 2){
            int l,r; cin >> l >> r;
            l--;
            S v = seg.prod(l, r);

            // fprintf(stderr, "%d : %d   %d : %d\n", v.first.first, v.first.second, v.second.first, v.second.second);

            // 2つ目の要素の個数
            cout << v.second.second << endl;
        }
    }
    return 0;
}