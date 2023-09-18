#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int M; cin >> M;
    int N = 3;
    vector<string> S(N);
    for(int i = 0; i < N; i++){
        cin >> S[i];
    }

    //t秒に1つボタンを押せるので、同じ数字があるとすれば最低でも3*M秒待てば揃えられる
    //全てのスロットに対して試せばO(N* NM)
    int ans = 1e6;

    for(int t1 = 0; t1 <= N*M; t1++){
        for(int t2 = 0; t2 <= N*M; t2++){
            for(int t3 = 0; t3 <= N*M; t3++){
                if(t1 == t2 || t2 == t3 || t3 == t1) continue;
                if(S[0][t1%M] == S[1][t2%M] && S[1][t2%M] == S[2][t3%M]){
                    // printf("slot = %c, t1=%d, t2=%d, t3=%d\n", S[0][t1%M], t1, t2, t3);
                    ans = min(ans, max({t1, t2, t3}));
                }
            }
        }
    }

    if(ans > 1e5) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}