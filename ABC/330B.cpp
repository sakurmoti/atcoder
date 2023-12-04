#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    ll N,L,R; cin >> N >> L >> R;
    
    for(int i = 0; i < N; i++){
        ll A; cin >> A;
        // |Y-A|を最小にするL <= Y <= R
        ll m;
        if(L <= A && A <= R){
            m = 0;
        }else{
            m = min(abs(L-A), abs(R-A));
        }

        ll X1 = A+m;
        ll X2 = A-m;
        // printf("X1=%lld X2 = %lld\n", X1, X2);
        if(L <= X1 && X1 <= R){
            cout << X1;
        }else{
            cout << X2;
        }

        if(i != N-1) cout << " ";
        else cout << endl;
    }
    return 0;
}