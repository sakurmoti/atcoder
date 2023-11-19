#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,Q; cin >> N >> Q;

    vector<bitset<200010>> Box(N+1);
    for(int i = 1; i <= N; i++){
        int c; cin >> c;
        Box[i].reset();
        Box[i].set(c); 
    }

    for(int q = 0; q < Q; q++){
        int a,b; cin >> a >> b;

        Box[b] |= Box[a];
        Box[a].reset();
        cout << Box[b].count() << endl;
    }

    return 0;
}