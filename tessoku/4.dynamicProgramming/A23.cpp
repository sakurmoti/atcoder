#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    vector<vector<int>> A(M+1, vector<int>(N));
    for(int i = 1; i <= M; i++){
        for(int j = 0; j < N; j++){
            cin >> A[i][j];
        }
    }

    //dp[i][S]をクーポンiまで選んだ時、無料で買える品物の集合Sであるときの最小の枚数とする
    //初期条件は最初から無料で買える品物はないのでdp[0][Φ]=0 (Φは空集合)
    //S={1,3}は101として添え字は5と扱う。S={1,2}なら011で3と扱う
    vector<vector<int>> dp(M+1, vector<int>(1 << N, 1e5));
    dp[0][0] = 0;
    for(int i = 1; i <= M; i++){
        for(int j = 0; j < (1<<N); j++){
            //Freeで1が立っている品物は無料で買えるとする
            bitset<15> Free(j);

            //クーポンiとの論理和
            for(int k = 0; k < N; k++){
                if(Free.test(k) || A.at(i).at(k) == 1){
                    Free.set(k);
                }
            }

            //無料になった品物を添え字に直す
            int idx = 0;
            for(int k = 0; k < 15; k++){
                if(Free.test(k)){
                    idx += (1<<k);
                }
            }

            //クーポンiを使わない場合
            dp.at(i).at(j) = min(dp.at(i).at(j), dp.at(i-1).at(j));

            //クーポンiを使う場合
            dp.at(i).at(idx) = min(dp.at(i).at(idx), dp.at(i).at(j)+1);

            //printf("i=%d, j=%d, dp=%d\n",i,j,dp[i][j]);
        }
    }

    int ans = dp.at(M).at((1<<N)-1);
    if(ans >= 1e5) cout << -1 << endl;
    else cout << ans << endl;
    
    return 0;
}
