#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,M,Q; cin >> N >> M >> Q;
    vector<int> W(N),V(N);
    for(int i = 0; i < N; i++){
        cin >> W[i] >> V[i];
    }

    vector<int> X(M);
    for(auto &_v : X) cin >> _v;

    while(Q--){
        int L,R; cin >> L >> R;
        
        for(int i = 0; i < M; i++){
            
        }
    }
    return 0;
}