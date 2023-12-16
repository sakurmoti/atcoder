#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    vector<ll> D(N);
    for(int i = 0; i < N; i++){
        cin >> D[i];
    }

    vector<ll> M(N);
    // D[i] = M[i]/2 + M[i+1]/2
    // 移項して M[i+1] = 2*D[i] - M[i]
    // 再帰的に M[i] = 2*D[i-1] - M[i-1];
    // M[i-1] = 2*D[i-2] - M[i-2] ...と続くので
    // M[i] = 2*D[i-1] - (2*D[i-2] - (2*D[i-3] - (...)))
    // Nは奇数から　M[i] = 2*D[i-1] - 2*D[i-2] + 2*D[i-3] - ... + 2*D[i-N-1] - M[i-N-1]
    // M[0]がわかれば後はそれぞれ O(1)

    int sign = 1;
    for(int i = 0; i < N; i++){
        M[0] += sign * D[ ((0 - (i+1)) + 2*N)%N];
        sign *= -1;
    }
    // cout << M[0] << endl;

    for(int i = 1; i < N; i++){
        M[i] = 2*D[i-1] - M[i-1];
    }

    for(int i = 0; i < N; i++){
        cout << M[i];
        if(i!=N-1) cout << " ";
        else cout << endl;
    }
    return 0;
}