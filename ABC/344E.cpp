#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    deque<int> A(N);
    for(auto &_v : A) cin >> _v;

    int Q; cin >> Q;
    while(Q--){
        int q; cin >> q;

        if(q == 1){
            int x,y; cin >> x >> y;
            A.insert(pos, y);
        }
    }
    return 0;
}