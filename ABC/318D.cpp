#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;

    vector<vector<ll>> D(N, vector<ll>(N, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i < j){
                cin >> D[i][j];
            }
        }
    }

    //bitDP
    //添え字はbitで表した集合を整数表現したもの
    //dp[{S}] := Sで立っている集合はすでに端点として決定しているときの、重みの総和の最大値
    vector<ll> dp((1<<N), -1e10);
    dp[0] = 0;

    for(int i = 0; i < (1<<N)-1; i++){
        bitset<16> b(i);

        //マッチングさせる頂点を決める。今回はまだ決定していない頂点のうち、最小のidxとする
        int v = -1;
        for(int j = 0; j < N; j++){
            if(!b.test(j)){
                v = j;
                break;
            }
        }
        if(v < 0) continue;

        
        //頂点の相手を探索する
        for(int j = 0; j < N; j++){
            if(!b.test(j)){
                int idx = i | (1<<v) | (1<<j); //bitsetの集合に加えて、頂点v、jを立てる
                dp[idx] = max(dp[idx], dp[i] + D[v][j]); //遷移
            }
        }
    }

    //dp[2^N - 1]、つまり全てのbitが立っていて、頂点が全て選択された状態
    //なお、頂点が奇数の場合は重み0の空頂点とマッチングさせると考えれば偶数と同じ
    cout << dp[(1<<N) -1] << endl;
    return 0;
}