#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    string S; cin >> S;
    vector<ll> C(N+1);
    for(int i = 1; i <= N; i++){
        cin >> C[i];
    }
    // 操作は要は反転するかしないか
    // 良い文字列はあるところを境にパリティになるように

    // csum1[i] := i番目までを1010101...となるようにするためのコスト
    // csum2[i] := i番目までを0101010...となるようにするためのコスト
    vector<ll> csum1(N+1, 0), csum2(N+1, 0);
    for(int i = 1; i <= N; i++){
        if(S[i-1] == '1'){
            if(i%2 == 1){
                // fprintf(stderr, "i = %d\n", i);
                csum1[i] = csum1[i-1];
                csum2[i] = csum2[i-1] + C[i];
            }else{
                csum1[i] = csum1[i-1] + C[i];
                csum2[i] = csum2[i-1];
            }

        }else{
            if(i%2 == 1){
                // fprintf(stderr, "i = %d\n", i);
                csum1[i] = csum1[i-1] + C[i];
                csum2[i] = csum2[i-1];
            }else{
                // fprintf(stderr, "i = %d\n", i);
                csum1[i] = csum1[i-1];
                csum2[i] = csum2[i-1] + C[i];
            }
        }
    }

    // for(auto &_v : csum1) cout << _v << " "; cout << endl;
    // for(auto &_v : csum2) cout << _v << " "; cout << endl;

    // 場所iを境に0101..と1010..が入れ替わるイメージ
    ll ans = 9e18;
    for(int i = 1; i <= N-1; i++){
        ll cost1 = csum1[i] + (csum2[N] - csum2[i]);
        ll cost2 = csum2[i] + (csum1[N] - csum1[i]);

        // fprintf(stderr, "i = %d c1 = %lld, c2 = %lld\n", i,cost1, cost2);
        // fprintf(stderr, "cost1 = %lld + (%lld - %lld) \n", csum1[i], csum2[N], csum2[i]);
        // fprintf(stderr, "cost2 = %lld + (%lld - %lld) \n", csum2[i], csum1[N], csum1[i]);
        // printf("\n");
        ans = min({ans, cost1, cost2});
    }

    cout << ans << endl;
    return 0;
}