#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M,X;
    cin >> N >> M >> X;

    vector<int> C(N);
    vector<vector<int>> A(N, vector<int>(M));
    for(int i = 0; i < N; i++){
        cin >> C[i];
        for(int j = 0; j < M; j++){
            cin >> A[i][j];
        }
    }

    ll ans = 1e18;
    for(int i = 0; i < (1<<N); i++){
        bitset<20> select(i);
        vector<ll> B(M,0);
        ll cost = 0;

        for(int j = 0; j < N; j++){
            if(select.test(j)){
                cost += C[j];
                for(int k = 0; k < M; k++){
                    B[k] += A[j][k];
                }
            }
        }

        bool flag = true;
        for(int j = 0; j < M; j++){
            if(B[j] < X){
                flag = false;
            }
        }

        if(flag) ans = min(ans, cost);
    }

    if(ans >= 1e17) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}