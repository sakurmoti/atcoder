#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    vector<vector<int>> idxs(N+1, {0});
    for(int i = 0; i < N; i++){
        idxs[A[i]].push_back(i+1);
    }
    for(int i = 0; i <= N; i++){
        idxs[i].push_back(N+1);
    }

    // for(auto u : idxs){
    //     for(auto v : u){
    //         cerr << v << " ";
    //     }
    //     cerr << endl;
    // }

    int Q; cin >> Q;
    while(Q--){
        int L,R,X; cin >> L >> R >> X;

        auto left = lower_bound(ALL(idxs[X]), L);
        auto right = upper_bound(ALL(idxs[X]), R);

        // cerr << *left << " " << *right << endl;
        cout << distance(left, right) << endl;
    }
    return 0;
}