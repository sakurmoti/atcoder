#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    ll N,P,Q,R; cin >> N >> P >> Q >> R;
    vector<ll> A(N+1);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }

    vector<ll> csum(N+1, 0);
    for(int i = 1; i <= N; i++){
        csum[i] = csum[i-1] + A[i];
    }

    auto binary_search = [&](int ok, int ng, ll comp) {
        int L = ng;
        while(abs(ok - ng) >= 2){
            int mid = (ok + ng)/2;
            if(csum[mid] - csum[L] >= comp){
                ok = mid;
            }else{
                ng = mid;
            }
        }

        return ok;    
    };

    for(int x = 0; x <= N-3; x++){
        fprintf(stderr, "\nx=%d ", x);

        int y = binary_search(N-2, x, P);
        if(csum[y] - csum[x] != P) continue;
        fprintf(stderr, "y=%d ", y);

        int z = binary_search(N-1, y, Q);
        if(csum[z] - csum[y] != Q) continue;
        fprintf(stderr, "z=%d ", z);

        int w = binary_search(N, z, R);
        if(csum[w] - csum[z] != R) continue;
        fprintf(stderr, "w=%d ", w);

        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;
    return 0;
}